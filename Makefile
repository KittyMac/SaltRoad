GIT_VERSION=$(shell git describe)

build:
	swift build --configuration release -Xswiftc -Osize -Xswiftc -gnone
	# -Xswiftc -emit-library
	cp .\.build\release\SaltRoadFrameworkLib.dll .\VSSaltRoadLib\SaltRoadLib\DLL

update:
	swift package update
	
clean:
	rm -rf .build

# Some useful tidbits for windows
#
# Install OpenSSH:
# https://www.hanselman.com/blog/how-to-ssh-into-a-windows-10-machine-from-linux-or-windows-or-anywhere
#
# Get-WindowsCapability -Online | ? Name -like 'OpenSSH*'
# Add-WindowsCapability -Online -Name OpenSSH.Server~~~~0.0.1.0
# Start-Service sshd
# Get-Service sshd
# Set-Service -Name sshd -StartupType 'Automatic'
# New-ItemProperty -Path "HKLM:\SOFTWARE\OpenSSH" -Name DefaultShell -Value "C:\Program Files\PowerShell\7\pwsh.exe" -PropertyType String -Force

# Install Make
# winget install GnuWin32.Make

# Install Swift
# https://github.com/pwsacademy/swift-setup/blob/main/platforms/windows/README.md
# Settings -> Update & Security -> Enable developer mode
# Microsoft Store -> Install "App Installer" by Microsoft
# winget install Git.Git
# winget install Python.Python.3.9
# (restart terminal)
# python -m ensurepip
# python -m pip install six
# winget install Microsoft.VisualStudio.2022.Community --force --custom "--add Microsoft.VisualStudio.Component.Windows11SDK.22000 --add Microsoft.VisualStudio.Component.VC.Tools.x86.x64"
# winget install Swift.Toolchain
# (restart terminal)
# swift --version