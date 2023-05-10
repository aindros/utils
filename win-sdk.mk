# See LICENSE file for copyright and license details.

ARCHITECTURE=x64

WIN_SDK_DRIVE=D:
WIN_SDK_VER=10.0.14393.0
WIN_SDK_LIBS="$(WIN_SDK_DRIVE)\Program Files (x86)\Windows Kits\10\Lib\$(WIN_SDK_VER)\um\$(ARCHITECTURE)\User32.Lib"  \
             "$(WIN_SDK_DRIVE)\Program Files (x86)\Windows Kits\10\Lib\$(WIN_SDK_VER)\um\$(ARCHITECTURE)\Gdi32.Lib"
