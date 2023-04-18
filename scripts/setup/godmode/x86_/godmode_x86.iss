; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName "God Mode"
#define MyAppVersion "1.0.0.0"
#define MyAppPublisher "New Pride Software - Services"
#define MyAppURL "https://github.com/Lateralus138/godmode"
#define MyAppExeName "godmode.exe"

[Setup]
; NOTE: The value of AppId uniquely identifies this application. Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{9C706C09-091C-4AAC-8A69-024C94E7FFC7}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultGroupName={#MyAppPublisher}\{#MyAppName} x86
DefaultDirName={autopf}\{#MyAppName}
LicenseFile=..\gplv3.txt
OutputDir=.\Output
OutputBaseFilename=godmode_x86_installer
SetupIconFile=..\godmode.ico
Compression=lzma
SolidCompression=yes
UninstallDisplayIcon={app}\{#MyAppExeName}
VersionInfoCompany=New Pride Software - Services
VersionInfoCopyright=� 2023 Ian Pride - New Pride Software - Services
VersionInfoDescription=Installer for the x86 version of God Mode.
VersionInfoProductName=God Mode x86 Installer
VersionInfoProductTextVersion=1.0.0.0
VersionInfoProductVersion=1.0.0.0
VersionInfoTextVersion=1.0.0.0
VersionInfoVersion=1.0.0.0
WizardStyle=modern
WizardImageFile=..\installer_banner.bmp
WizardImageStretch=yes
WizardSmallImageFile=..\installer_toplogo.bmp

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: ".\{#MyAppExeName}"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\godmode.ico"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\godmode.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\gplv3.txt"; DestDir: "{app}"; Flags: ignoreversion
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
; Name: "{group}\{#MyAppName} x86"; Filename: "{app}\{#MyAppExeName}"
Name: "{autodesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon

[Run]
Filename: "{cmd}"; Parameters: "/c reg add HKEY_CURRENT_USER\Environment /v PATH /d ""%PATH%;{autopf}\{#MyAppName}"" /f"; \
    Description: "Add program directory to %PATH%"; \
    Flags: nowait postinstall skipifsilent runascurrentuser runhidden; 
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent unchecked

[UninstallRun]
Filename: "{cmd}"; Parameters: "/c reg add HKEY_CURRENT_USER\Environment /v PATH /d ""%PATH:{autopf}\{#MyAppName}=%"" /f"; \
    Flags: runhidden; RunOnceId: "Uninstallx86"; 

