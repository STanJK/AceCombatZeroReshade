#!/usr/bin/env bash
set -euo pipefail
if [[ $# -ne 2 ]]; then
    echo "Usage: GHIDRA_INSTALL_DIR=/path/to/ghidra JAVA_HOME=/path/to/jdk25 $0 /path/to/acz.exe /fresh/output/directory" >&2
    exit 2
fi
: "${GHIDRA_INSTALL_DIR:?Set GHIDRA_INSTALL_DIR to a Ghidra 12.2 installation}"
script_dir="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
repo_dir="$(cd -- "$script_dir/../.." && pwd)"
binary_path="$(python3 -c 'from pathlib import Path; import sys; print(Path(sys.argv[1]).resolve())' "$1")"
output_dir="$(python3 -c 'from pathlib import Path; import sys; print(Path(sys.argv[1]).resolve())' "$2")"
if [[ -e "$output_dir/projects/ACZCoop.gpr" ]]; then
    echo "Use a fresh output directory; refusing to overwrite an existing research project." >&2
    exit 2
fi
python3 "$script_dir/pe_evidence.py" "$binary_path" "$output_dir/index"
mkdir -p "$output_dir/projects" "$output_dir/selected"
"$GHIDRA_INSTALL_DIR/support/analyzeHeadless" "$output_dir/projects" ACZCoop \
    -import "$binary_path" -scriptPath "$script_dir" -max-cpu 4 \
    -analysisTimeoutPerFile 900 \
    -postScript ApplyKnownInputContracts.java \
    -postScript ExportSelectedFunctions.java "$output_dir/selected" "$repo_dir/docs/reverse-engineering/coop/evidence/selection.txt" \
    -postScript ExportProgramIndex.java "$output_dir/index" \
    -log "$output_dir/analysis.log" -scriptlog "$output_dir/scripts.log"
echo "Static extraction finished: $output_dir"
echo "Use package_coop_evidence.py only when intentionally refreshing the repository evidence."
