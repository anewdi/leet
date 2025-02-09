with import <nixpkgs> { };
mkShell {
  hardeningDisable = [ "all" ];
  packages = [
    clang-tools
    gdb
    vscode-extensions.ms-vscode.cpptools
    valgrind
  ];
  CDAP = "${pkgs.vscode-extensions.ms-vscode.cpptools}/share/vscode/extensions//ms-vscode.cpptools/debugAdapters/bin/OpenDebugAD7";
}
