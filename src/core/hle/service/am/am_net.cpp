// Copyright 2014 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "common/archives.h"
#include "core/hle/service/am/am_net.h"

namespace Service::AM {

AM_NET::AM_NET(std::shared_ptr<Module> am) : Module::Interface(std::move(am), "am:net", 5) {
    static const FunctionInfo functions[] = {
        // clang-format off
        {IPC::MakeHeader(0x0001, 1, 0), &AM_NET::GetNumPrograms, "GetNumPrograms"},
        {IPC::MakeHeader(0x0002, 2, 2), &AM_NET::GetProgramList, "GetProgramList"},
        {IPC::MakeHeader(0x0003, 2, 4), &AM_NET::GetProgramInfos, "GetProgramInfos"},
        {IPC::MakeHeader(0x0004, 3, 0), &AM_NET::DeleteUserProgram, "DeleteUserProgram"},
        {IPC::MakeHeader(0x0005, 3, 0), &AM_NET::GetProductCode, "GetProductCode"},
        {IPC::MakeHeader(0x0006, 3, 0), nullptr, "GetStorageId"},
        {IPC::MakeHeader(0x0007, 2, 0), &AM_NET::DeleteTicket, "DeleteTicket"},
        {IPC::MakeHeader(0x0008, 0, 0), &AM_NET::GetNumTickets, "GetNumTickets"},
        {IPC::MakeHeader(0x0009, 2, 2), &AM_NET::GetTicketList, "GetTicketList"},
        {IPC::MakeHeader(0x000A, 0, 0), nullptr, "GetDeviceID"},
        {IPC::MakeHeader(0x000B, 1, 0), nullptr, "GetNumImportTitleContexts"},
        {IPC::MakeHeader(0x000C, 2, 2), nullptr, "GetImportTitleContextList"},
        {IPC::MakeHeader(0x000D, 2, 4), nullptr, "GetImportTitleContexts"},
        {IPC::MakeHeader(0x000E, 3, 0), nullptr, "DeleteImportTitleContext"},
        {IPC::MakeHeader(0x000F, 3, 0), nullptr, "GetNumImportContentContexts"},
        {IPC::MakeHeader(0x0010, 4, 2), nullptr, "GetImportContentContextList"},
        {IPC::MakeHeader(0x0011, 4, 4), nullptr, "GetImportContentContexts"},
        {IPC::MakeHeader(0x0012, 4, 2), nullptr, "DeleteImportContentContexts"},
        {IPC::MakeHeader(0x0013, 1, 0), &AM_NET::NeedsCleanup, "NeedsCleanup"},
        {IPC::MakeHeader(0x0014, 1, 0), nullptr, "DoCleanup"},
        {IPC::MakeHeader(0x0015, 1, 0), nullptr, "DeleteAllImportContexts"},
        {IPC::MakeHeader(0x0016, 0, 0), nullptr, "DeleteAllTemporaryPrograms"},
        {IPC::MakeHeader(0x0017, 1, 4), nullptr, "ImportTwlBackupLegacy"},
        {IPC::MakeHeader(0x0018, 2, 0), nullptr, "InitializeTitleDatabase"},
        {IPC::MakeHeader(0x0019, 1, 0), nullptr, "QueryAvailableTitleDatabase"},
        {IPC::MakeHeader(0x001A, 3, 0), nullptr, "CalcTwlBackupSize"},
        {IPC::MakeHeader(0x001B, 5, 4), nullptr, "ExportTwlBackup"},
        {IPC::MakeHeader(0x001C, 2, 4), nullptr, "ImportTwlBackup"},
        {IPC::MakeHeader(0x001D, 0, 0), nullptr, "DeleteAllTwlUserPrograms"},
        {IPC::MakeHeader(0x001E, 3, 8), nullptr, "ReadTwlBackupInfo"},
        {IPC::MakeHeader(0x001F, 1, 0), nullptr, "DeleteAllExpiredUserPrograms"},
        {IPC::MakeHeader(0x0020, 0, 0), nullptr, "GetTwlArchiveResourceInfo"},
        {IPC::MakeHeader(0x0021, 1, 2), nullptr, "GetPersonalizedTicketInfoList"},
        {IPC::MakeHeader(0x0022, 2, 0), nullptr, "DeleteAllImportContextsFiltered"},
        {IPC::MakeHeader(0x0023, 2, 0), nullptr, "GetNumImportTitleContextsFiltered"},
        {IPC::MakeHeader(0x0024, 3, 2), nullptr, "GetImportTitleContextListFiltered"},
        {IPC::MakeHeader(0x0025, 3, 0), nullptr, "CheckContentRights"},
        {IPC::MakeHeader(0x0026, 1, 4), nullptr, "GetTicketLimitInfos"},
        {IPC::MakeHeader(0x0027, 1, 4), nullptr, "GetDemoLaunchInfos"},
        {IPC::MakeHeader(0x0028, 4, 8), nullptr, "ReadTwlBackupInfoEx"},
        {IPC::MakeHeader(0x0029, 2, 2), nullptr, "DeleteUserProgramsAtomically"},
        {IPC::MakeHeader(0x002A, 3, 0), nullptr, "GetNumExistingContentInfosSystem"},
        {IPC::MakeHeader(0x002B, 5, 2), nullptr, "ListExistingContentInfosSystem"},
        {IPC::MakeHeader(0x002C, 2, 4), nullptr, "GetProgramInfosIgnorePlatform"},
        {IPC::MakeHeader(0x002D, 3, 0), nullptr, "CheckContentRightsIgnorePlatform"},
        {IPC::MakeHeader(0x0401, 2, 0), nullptr, "UpdateFirmwareTo"},
        {IPC::MakeHeader(0x0402, 1, 0), &AM_NET::BeginImportProgram, "BeginImportProgram"},
        {IPC::MakeHeader(0x0403, 0, 0), nullptr, "BeginImportProgramTemporarily"},
        {IPC::MakeHeader(0x0404, 0, 2), nullptr, "CancelImportProgram"},
        {IPC::MakeHeader(0x0405, 0, 2), &AM_NET::EndImportProgram, "EndImportProgram"},
        {IPC::MakeHeader(0x0406, 0, 2), nullptr, "EndImportProgramWithoutCommit"},
        {IPC::MakeHeader(0x0407, 3, 2), nullptr, "CommitImportPrograms"},
        {IPC::MakeHeader(0x0408, 1, 2), &AM_NET::GetProgramInfoFromCia, "GetProgramInfoFromCia"},
        {IPC::MakeHeader(0x0409, 0, 4), &AM_NET::GetSystemMenuDataFromCia, "GetSystemMenuDataFromCia"},
        {IPC::MakeHeader(0x040A, 0, 2), &AM_NET::GetDependencyListFromCia, "GetDependencyListFromCia"},
        {IPC::MakeHeader(0x040B, 0, 2), &AM_NET::GetTransferSizeFromCia, "GetTransferSizeFromCia"},
        {IPC::MakeHeader(0x040C, 0, 2), &AM_NET::GetCoreVersionFromCia, "GetCoreVersionFromCia"},
        {IPC::MakeHeader(0x040D, 1, 2), &AM_NET::GetRequiredSizeFromCia, "GetRequiredSizeFromCia"},
        {IPC::MakeHeader(0x040E, 3, 2), nullptr, "CommitImportProgramsAndUpdateFirmwareAuto"},
        {IPC::MakeHeader(0x040F, 0, 0), nullptr, "UpdateFirmwareAuto"},
        {IPC::MakeHeader(0x0410, 3, 0), &AM_NET::DeleteProgram, "DeleteProgram"},
        {IPC::MakeHeader(0x0411, 1, 4), nullptr, "GetTwlProgramListForReboot"},
        {IPC::MakeHeader(0x0412, 0, 0), nullptr, "GetSystemUpdaterMutex"},
        {IPC::MakeHeader(0x0413, 0, 2), &AM_NET::GetMetaSizeFromCia, "GetMetaSizeFromCia"},
        {IPC::MakeHeader(0x0414, 1, 4), &AM_NET::GetMetaDataFromCia, "GetMetaDataFromCia"},
        {IPC::MakeHeader(0x0415, 2, 0), nullptr, "CheckDemoLaunchRights"},
        {IPC::MakeHeader(0x0416, 3, 0), nullptr, "GetInternalTitleLocationInfo"},
        {IPC::MakeHeader(0x0417, 3, 0), nullptr, "PerpetuateAgbSaveData"},
        {IPC::MakeHeader(0x0418, 1, 0), nullptr, "BeginImportProgramForOverWrite"},
        {IPC::MakeHeader(0x0419, 0, 0), nullptr, "BeginImportSystemProgram"},
        {IPC::MakeHeader(0x0801, 0, 0), nullptr, "BeginImportTicket"},
        {IPC::MakeHeader(0x0802, 0, 2), nullptr, "CancelImportTicket"},
        {IPC::MakeHeader(0x0803, 0, 2), nullptr, "EndImportTicket"},
        {IPC::MakeHeader(0x0804, 4, 0), nullptr, "BeginImportTitle"},
        {IPC::MakeHeader(0x0805, 0, 0), nullptr, "StopImportTitle"},
        {IPC::MakeHeader(0x0806, 3, 0), nullptr, "ResumeImportTitle"},
        {IPC::MakeHeader(0x0807, 0, 0), nullptr, "CancelImportTitle"},
        {IPC::MakeHeader(0x0808, 0, 0), nullptr, "EndImportTitle"},
        {IPC::MakeHeader(0x0809, 3, 2), nullptr, "CommitImportTitles"},
        {IPC::MakeHeader(0x080A, 0, 0), nullptr, "BeginImportTmd"},
        {IPC::MakeHeader(0x080B, 0, 2), nullptr, "CancelImportTmd"},
        {IPC::MakeHeader(0x080C, 1, 2), nullptr, "EndImportTmd"},
        {IPC::MakeHeader(0x080D, 1, 2), nullptr, "CreateImportContentContexts"},
        {IPC::MakeHeader(0x080E, 1, 0), nullptr, "BeginImportContent"},
        {IPC::MakeHeader(0x080F, 0, 2), nullptr, "StopImportContent"},
        {IPC::MakeHeader(0x0810, 1, 0), nullptr, "ResumeImportContent"},
        {IPC::MakeHeader(0x0811, 0, 2), nullptr, "CancelImportContent"},
        {IPC::MakeHeader(0x0812, 0, 2), nullptr, "EndImportContent"},
        {IPC::MakeHeader(0x0813, 0, 0), nullptr, "GetNumCurrentImportContentContexts"},
        {IPC::MakeHeader(0x0814, 1, 2), nullptr, "GetCurrentImportContentContextList"},
        {IPC::MakeHeader(0x0815, 1, 4), nullptr, "GetCurrentImportContentContexts"},
        {IPC::MakeHeader(0x0816, 5, 6), nullptr, "Sign"},
        {IPC::MakeHeader(0x0817, 5, 6), nullptr, "Verify"},
        {IPC::MakeHeader(0x0818, 1, 2), nullptr, "GetDeviceCert"},
        {IPC::MakeHeader(0x0819, 4, 8), nullptr, "ImportCertificates"},
        {IPC::MakeHeader(0x081A, 1, 2), nullptr, "ImportCertificate"},
        {IPC::MakeHeader(0x081B, 3, 2), nullptr, "CommitImportTitlesAndUpdateFirmwareAuto"},
        {IPC::MakeHeader(0x081C, 4, 0), nullptr, "DeleteTicketId"},
        {IPC::MakeHeader(0x081D, 2, 0), nullptr, "GetNumTicketIds"},
        {IPC::MakeHeader(0x081E, 4, 2), nullptr, "GetTicketIdList"},
        {IPC::MakeHeader(0x081F, 2, 0), nullptr, "GetNumTicketsOfProgram"},
        {IPC::MakeHeader(0x0820, 4, 2), nullptr, "ListTicketInfos"},
        {IPC::MakeHeader(0x0821, 5, 2), nullptr, "GetRightsOnlyTicketData"},
        {IPC::MakeHeader(0x0822, 0, 0), nullptr, "GetNumCurrentContentInfos"},
        {IPC::MakeHeader(0x0823, 1, 4), nullptr, "FindCurrentContentInfos"},
        {IPC::MakeHeader(0x0824, 2, 2), nullptr, "ListCurrentContentInfos"},
        {IPC::MakeHeader(0x0825, 4, 2), nullptr, "CalculateContextRequiredSize"},
        {IPC::MakeHeader(0x0826, 1, 2), nullptr, "UpdateImportContentContexts"},
        {IPC::MakeHeader(0x0827, 0, 0), nullptr, "DeleteAllDemoLaunchInfos"},
        {IPC::MakeHeader(0x0828, 3, 0), nullptr, "BeginImportTitleForOverWrite"},
        // clang-format on
    };
    RegisterHandlers(functions);
}

} // namespace Service::AM

SERIALIZE_EXPORT_IMPL(Service::AM::AM_NET)
