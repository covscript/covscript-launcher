﻿
#define MY_VS_FFI_FILEFLAGSMASK  0x0000003FL
#define MY_VOS_NT_WINDOWS32  0x00040004L
#define MY_VOS_CE_WINDOWS32  0x00050004L

#define MY_VFT_APP  0x00000001L

#define MY_AUTHOR_NAME "Michael Lee"
#define MY_COPYRIGHT "Copyright (C) 2020 Michael Lee"

#define MY_VERSION "1.0.0.0"
#define MY_VER 1,0,0,0

#define MY_VERSION_INFO(fileType, descr, intName, origName)  \
LANGUAGE 9, 1 \
1 VERSIONINFO \
  FILEVERSION MY_VER \
  PRODUCTVERSION MY_VER \
  FILEFLAGSMASK MY_VS_FFI_FILEFLAGSMASK \
  FILEOS MY_VOS_NT_WINDOWS32 \
  FILETYPE fileType \
  FILESUBTYPE 0x0L \
BEGIN \
    BLOCK "StringFileInfo" \
    BEGIN  \
        BLOCK "040904b0" \
        BEGIN \
            VALUE "CompanyName", "Covariant.CN" \
            VALUE "FileDescription", descr \
            VALUE "FileVersion", MY_VERSION  \
            VALUE "InternalName", intName \
            VALUE "LegalCopyright", MY_COPYRIGHT \
            VALUE "OriginalFilename", origName \
            VALUE "ProductName", "Covariant Script Programming Language" \
            VALUE "ProductVersion", MY_VERSION \
        END \
    END \
    BLOCK "VarFileInfo" \
    BEGIN \
        VALUE "Translation", 0x409, 1200 \
    END \
END

#define MY_VERSION_INFO_APP(descr, intName) MY_VERSION_INFO(MY_VFT_APP, descr, intName, intName ".exe")
