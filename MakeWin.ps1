
swift build --configuration debug

# TODO: copy all required DLLs to dist

Copy-Item -Path ".build/debug/SaltRoadFrameworkLib.lib" "dist/SaltRoadFrameworkLib.lib"
Copy-Item -Path ".build/debug/SaltRoadFrameworkLib.dll" "dist/SaltRoadFrameworkLib.dll"
Copy-Item -Path "Sources/SaltRoadCPP/include/SaltRoadCPP.h" "dist/SaltRoadCPP.h"