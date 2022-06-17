# Build Instructions

```shell
$ cmake -S . -B build -D CMAKE_CXX_COMPILER="clang" -G Ninja
$ cmake --build build
<build fails>
```

<details>
<summary>Build Failure</summary>

```
C:\Users\pigeon\git\github.com\PigeonF\vcpkg-abseil-ignore-4221>cmake -S . -B build -D CMAKE_CXX_COMPILER="clang"
-- Building for: Ninja
-- Running vcpkg install
Detecting compiler hash for triplet "x64-windows"...
The following packages will be built and installed:
    abseil[core]:x64-windows -> 20211102.1 -- C:\Users\pigeon\git\github.com\PigeonF\vcpkg-abseil-ignore-4221\vcpkg\buildtrees\versioning_\versions\abseil\962a81319706d17c9e90bd0b873659ec7c75178a
  * vcpkg-cmake[core]:x64-windows -> 2022-05-10#1 -- C:\Users\pigeon\git\github.com\PigeonF\vcpkg-abseil-ignore-4221\vcpkg\buildtrees\versioning_\versions\vcpkg-cmake\8b07d914c90cf8f611973318c85d3af13201e3f9
  * vcpkg-cmake-config[core]:x64-windows -> 2022-02-06#1 -- C:\Users\pigeon\git\github.com\PigeonF\vcpkg-abseil-ignore-4221\vcpkg\buildtrees\versioning_\versions\vcpkg-cmake-config\8d54cc4f487d51b655abec5f9c9c3f86ca83311f
Additional packages (*) will be modified to complete this operation.
Restored 3 packages from C:\Users\pigeon\AppData\Local\vcpkg\archives in 639.4 ms. Use --debug to see more details.
Installing 1/3 vcpkg-cmake-config:x64-windows...
Elapsed time to handle vcpkg-cmake-config:x64-windows: 18.03 ms
Installing 2/3 vcpkg-cmake:x64-windows...
Elapsed time to handle vcpkg-cmake:x64-windows: 95.61 ms
Installing 3/3 abseil:x64-windows...
Elapsed time to handle abseil:x64-windows: 762.1 ms

Total elapsed time: 4.091 s

abseil provides CMake targets:
    # this is heuristically generated, and may not be correct
    find_package(absl CONFIG REQUIRED)
    # note: 134 additional targets are not displayed.    target_link_libraries(main PRIVATE absl::any absl::base absl::bits absl::city)

-- Running vcpkg install - done
-- The CXX compiler identification is Clang 14.0.5 with GNU-like command-line
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: C:/Users/pigeon/scoop/apps/llvm/current/bin/clang.exe - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Failed
-- Looking for pthread_create in pthreads
-- Looking for pthread_create in pthreads - not found
-- Looking for pthread_create in pthread
-- Looking for pthread_create in pthread - not found
-- Check if compiler accepts -pthread
-- Check if compiler accepts -pthread - no
-- Found Threads: TRUE  
-- Configuring done
-- Generating done
-- Build files have been written to: C:/Users/pigeon/git/github.com/PigeonF/vcpkg-abseil-ignore-4221/build

C:\Users\pigeon\git\github.com\PigeonF\vcpkg-abseil-ignore-4221>cmake --build build
[2/2] Linking CXX executable main.exe
FAILED: main.exe
cmd.exe /C "cd . && C:\Users\pigeon\scoop\apps\llvm\current\bin\clang.exe -fuse-ld=lld-link -nostartfiles -nostdlib -O3 -DNDEBUG -D_DLL -D_MT -Xclang --dependent-lib=msvcrt -Xlinker /subsang --dependent-lib=msvcrt -Xlinker /subsystem:console CMakeFiles/main.dir/main.cc.obj -o main.exe -Xlinker /MANIFEST:EMBED -Xlinker /implib:main.ion:0.0   vcpkg_installed/x64-windows/liblib -Xlinker /pdb:main.pdb -Xlinker /version:0.0   vcpkg_installed/x64-windows/lib/abseil_dll.lib  -ignore:4221  -lkernel32 -luser32 -lgdi32 -lwin.exe /C "cd /D C:\Users\pigeon\git\githubspool -lshell32 -lole32 -loleaut32 -luuid -lcomdlg32 -ladvapi32 -loldnames  && cmd.exe /C "cd /D C:\Users\pigeon\git\github.com\PigeonF\vcpkg-abseit/github.com/PigeonF/vcpkg-abseil-ignoreil-ignore-4221\build && "C:\Program Files\PowerShell\7\pwsh.exe" -noprofile -executionpolicy Bypass -file C:/Users/pigeon/git/github.com/PigeonF/v -installedDir C:/Users/pigeon/git/githubcpkg-abseil-ignore-4221/vcpkg/scripts/buildsystems/msbuild/applocal.ps1 -targetBinary C:/Users/pigeon/git/github.com/PigeonF/vcpkg-abseil-ignore-4221/build/main.exe -installedDir C:/Users/pigeon/git/github.com/PigeonF/vcpkg-abseil-ignore-4221/build/vcpkg_installed/x64-windows/bin -OutVariable out""
clang: error: unknown argument: '-ignore:4221'
ninja: build stopped: subcommand failed.
```

</details>

Removing all references to `-ignore:4221` in `abslTargets.cmake` fixes the build.

```shell
$ sed -i "s/;-ignore:4221//g" build\vcpkg_installed\x64-windows\share\absl\abslTargets.cmake
$ sed -i "s/;\\$<LINK_ONLY:-ignore:4221>//g" build\vcpkg_installed\x64-windows\share\absl\abslTargets.cmake
$ cmake --build build
$ build\main.exe
OK
```
