#include "as608.h"

QLibrary SynoAPI("SynoAPIEx.dll");

as608::as608()
{

}
int WINAPI as608::PSGetUSBDevNum(int *iNums)
{
    if (myPSGetUSBDevNum!= NULL )
    {
        myPSGetUSBDevNum(iNums);
    }else {
        qDebug()<<"PSGetUSBDevNum失败";
    }
}

int WINAPI as608::PSGetUDiskNum(int* iNums)
{
    if (myPSGetUDiskNum!= NULL )
    {
        myPSGetUDiskNum( iNums);
    }else {
        qDebug()<<"PSGetUDiskNum失败";
    }
}

int WINAPI as608::PSOpenDeviceEx(HANDLE* pHandle, int nDeviceType,int iCom,int iBaud,int nPackageSize,int iDevNum)
{
    if (myPSOpenDeviceEx!= NULL )
    {
        myPSOpenDeviceEx( pHandle,  nDeviceType, iCom, iBaud=1, nPackageSize, iDevNum);
    }else {
        qDebug()<<"PSOpenDeviceEx失败";
    }
}

int WINAPI as608::PSCloseDeviceEx(HANDLE hHandle)
{
    if (myPSCloseDeviceEx!= NULL )
    {
        myPSCloseDeviceEx( hHandle);
    }else {
        qDebug()<<"PSCloseDeviceEx失败";
    }
}

int WINAPI as608::JPSetPackSize(HANDLE hHandle, int nPackSize)
{
    if (myJPSetPackSize!= NULL )
    {
        myJPSetPackSize( hHandle,  nPackSize);
    }else {
        qDebug()<<"JPSetPackSize失败";
    }
}

int WINAPI as608::PSAutoOpen(HANDLE* pHandle,int* type, int nAddr,UINT uPwd,int bVfy)
{
    if (myPSAutoOpen!= NULL )
    {
        myPSAutoOpen( pHandle, type,  nAddr, uPwd, bVfy);
    }else {
        qDebug()<<"PSAutoOpen失败";
    }
}

int WINAPI as608::PSGetImage(HANDLE hHandle,int nAddr)
{
    if (myPSGetImage!= NULL )
    {
        myPSGetImage( hHandle, nAddr);
    }else {
        qDebug()<<"PSGetImage失败";
    }
}

int WINAPI as608::PSGetImage_Enroll(HANDLE hHandle,int nAddr)
{
    if (myPSGetImage_Enroll!= NULL )
    {
        myPSGetImage_Enroll( hHandle, nAddr);
    }else {
        qDebug()<<"PSGetImage_Enroll失败";
    }
}

int WINAPI as608::PSGenChar(HANDLE hHandle,int nAddr,int iBufferID)
{
    if (myPSGenChar!= NULL )
    {
        myPSGenChar( hHandle, nAddr, iBufferID);
    }else {
        qDebug()<<"PSGenChar失败";
    }
}

int WINAPI as608::PSMatch(HANDLE hHandle,int nAddr,int* iScore)
{
    if (myPSMatch!= NULL )
    {
        myPSMatch( hHandle, nAddr, iScore);
    }else {
        qDebug()<<"PSMatch失败";
    }
}

int WINAPI as608::PSSearch(HANDLE hHandle,int nAddr,int iBufferID, int iStartPage, int iPageNum, int* iMbAddress,int* iscore)
{
    if (myPSSearch!= NULL )
    {
        myPSSearch( hHandle, nAddr, iBufferID,  iStartPage,  iPageNum,  iMbAddress, iscore);
    }else {
        qDebug()<<"PSSearch失败";
    }
}

int	WINAPI as608::PSRegModule(HANDLE hHandle,int nAddr)
{
    if (myPSRegModule!= NULL )
    {
        myPSRegModule( hHandle, nAddr);
    }else {
        qDebug()<<"PSRegModule失败";
    }
}

int WINAPI as608::PSStoreChar(HANDLE hHandle,int nAddr,int iBufferID, int iPageID)
{
    if (myPSStoreChar!= NULL )
    {
        myPSStoreChar( hHandle, nAddr, iBufferID,  iPageID);
    }else {
        qDebug()<<"PSStoreChar失败";
    }
}

int WINAPI as608::PSLoadChar(HANDLE hHandle,int nAddr,int iBufferID,int iPageID)
{
    if (myPSLoadChar!= NULL )
    {
        myPSLoadChar( hHandle, nAddr, iBufferID, iPageID);
    }else {
        qDebug()<<"PSLoadChar失败";
    }
}

int WINAPI as608::PSUpChar(HANDLE hHandle,int nAddr,int iBufferID, unsigned char* pTemplet, int* iTempletLength)
{
    if (myPSUpChar!= NULL )
    {
        myPSUpChar( hHandle, nAddr, iBufferID,  pTemplet,  iTempletLength);
    }else {
        qDebug()<<"PSUpChar失败";
    }
}

int WINAPI as608::PSDownChar(HANDLE hHandle,int nAddr,int iBufferID, unsigned char* pTemplet, int iTempletLength)
{
    if (myPSDownChar!= NULL )
    {
        myPSDownChar( hHandle, nAddr, iBufferID,  pTemplet,  iTempletLength);
    }else {
        qDebug()<<"PSDownChar失败";
    }
}

int WINAPI as608::PSDownChar_Test(HANDLE hHandle,int nAddr,int iBufferID, unsigned char* pTemplet, int iTempletLength,int nAddr1,int ipack,WORD whead,WORD wCheck,int iErr)
{
    if (myPSDownChar_Test!= NULL )
    {
        myPSDownChar_Test( hHandle, nAddr, iBufferID,  pTemplet,  iTempletLength, nAddr1, ipack,whead=0xEF01,wCheck=0x0000, iErr);
    }else {
        qDebug()<<"PSDownChar_Test失败";
    }
}

int WINAPI as608::PSUpImage(HANDLE hHandle,int nAddr,unsigned char* pImageData, int* iImageLength)
{
    if (myPSUpImage!= NULL )
    {
        myPSUpImage( hHandle, nAddr, pImageData,  iImageLength);
    }else {
        qDebug()<<"PSUpImage失败";
    }
}

int WINAPI as608::PSDownImage(HANDLE hHandle,int nAddr,unsigned char* pImageData, int iLength)
{
    if (myPSDownImage!= NULL )
    {
        myPSDownImage( hHandle, nAddr, pImageData,  iLength);
    }else {
        qDebug()<<"PSDownImage失败";
    }
}

int WINAPI as608::PSImgData2BMP(unsigned char* pImgData,const char* pImageFile)
{
    if (myPSImgData2BMP!= NULL )
    {
        myPSImgData2BMP( pImgData, pImageFile);
    }else {
        qDebug()<<"PSImgData2BMP失败";
    }
}

int WINAPI as608::PSGetImgDataFromBMP(HANDLE hHandle,const char* pImageFile,unsigned char* pImageData,int* pnImageLen)
{
    if (myPSGetImgDataFromBMP!= NULL )
    {
        myPSGetImgDataFromBMP( hHandle, pImageFile, pImageData, pnImageLen);
    }else {
        qDebug()<<"PSGetImgDataFromBMP失败";
    }
}

int WINAPI as608::PSDelChar(HANDLE hHandle,int nAddr,int iStartPageID,int nDelPageNum)
{
    if (myPSDelChar!= NULL )
    {
        myPSDelChar( hHandle, nAddr, iStartPageID, nDelPageNum);
    }else {
        qDebug()<<"PSDelChar失败";
    }
}

int WINAPI as608::PSEmpty(HANDLE hHandle,int nAddr)
{
    if (myPSEmpty!= NULL )
    {
        myPSEmpty( hHandle, nAddr);
    }else {
        qDebug()<<"PSEmpty失败";
    }
}

int WINAPI as608::PSReadParTable(HANDLE hHandle,int nAddr,unsigned char* pParTable)
{
    if (myPSReadParTable!= NULL )
    {
        myPSReadParTable( hHandle, nAddr, pParTable);
    }else {
        qDebug()<<"PSReadParTable失败";
    }
}

int WINAPI as608::PSReadInfPage(HANDLE hHandle,int nAddr, unsigned char* pInf)
{
    if (myPSReadInfPage!= NULL )
    {
        myPSReadInfPage( hHandle, nAddr,  pInf);
    }else {
        qDebug()<<"PSReadInfPage失败";
    }
}

int WINAPI as608::PSHighSpeedSearch(HANDLE hHandle,int nAddr,int iBufferID, int iStartPage, int iPageNum, int* iMbAddress,int* iscore)
{
    if (myPSHighSpeedSearch!= NULL )
    {
        myPSHighSpeedSearch( hHandle, nAddr, iBufferID,  iStartPage,  iPageNum,  iMbAddress, iscore);
    }else {
        qDebug()<<"PSHighSpeedSearch失败";
    }
}

int WINAPI as608::PSTemplateNum(HANDLE hHandle,int nAddr,int* iMbNum)
{
    if (myPSTemplateNum!= NULL )
    {
        myPSTemplateNum( hHandle, nAddr, iMbNum);
    }else {
        qDebug()<<"PSTemplateNum失败";
    }
}

int WINAPI as608::PSGenBinImage(HANDLE hHandle,int nAddr, int nImgType)
{
    if (myPSGenBinImage!= NULL )
    {
        myPSGenBinImage( hHandle, nAddr,  nImgType);
    }else {
        qDebug()<<"PSGenBinImage失败";
    }
}

int WINAPI as608::PSPowerDown(HANDLE hHandle,int nAddr)
{
    if (myPSPowerDown!= NULL )
    {
        myPSPowerDown( hHandle, nAddr);
    }else {
        qDebug()<<"PSPowerDown失败";
    }
}

int WINAPI as608::PSSetPwd(HANDLE hHandle,int nAddr,unsigned char* pPassword)
{
    if (myPSSetPwd!= NULL )
    {
        myPSSetPwd( hHandle, nAddr, pPassword);
    }else {
        qDebug()<<"PSSetPwd失败";
    }
}

int WINAPI as608::PSVfyPwd(HANDLE hHandle,int nAddr,unsigned char* pPassword)
{
    if (myPSVfyPwd!= NULL )
    {
        myPSVfyPwd( hHandle, nAddr, pPassword);
    }else {
        qDebug()<<"PSVfyPwd失败";
    }
}

int WINAPI as608::PSReset(HANDLE hHandle,int nAddr)
{
    if (myPSReset!= NULL )
    {
        myPSReset( hHandle, nAddr);
    }else {
        qDebug()<<"PSReset失败";
    }
}

int WINAPI as608::PSReadInfo(HANDLE hHandle,int nAddr,int nPage,unsigned char* UserContent)
{
    if (myPSReadInfo!= NULL )
    {
        myPSReadInfo( hHandle, nAddr, nPage, UserContent);
    }else {
        qDebug()<<"PSReadInfo失败";
    }
}

int WINAPI as608::PSWriteInfo(HANDLE hHandle,int nAddr,int nPage,unsigned char* UserContent)
{
    if (myPSWriteInfo!= NULL )
    {
        myPSWriteInfo( hHandle, nAddr, nPage, UserContent);
    }else {
        qDebug()<<"PSWriteInfo失败";
    }
}

int WINAPI as608::PSEnroll(HANDLE hHandle,int nAddr,int* nID)
{
    if (myPSEnroll!= NULL )
    {
        myPSEnroll( hHandle, nAddr, nID);
    }else {
        qDebug()<<"PSEnroll失败";
    }
}

int WINAPI as608::PSWriteReg(HANDLE hHandle,int nAddr,int iRegAddr,int iRegValue)
{
    if (myPSWriteReg!= NULL )
    {
        myPSWriteReg( hHandle, nAddr, iRegAddr, iRegValue);
    }else {
        qDebug()<<"PSWriteReg失败";
    }
}

int WINAPI as608::PSSetBaud(HANDLE hHandle,int nAddr,int nBaudNum)
{
    if (myPSSetBaud!= NULL )
    {
        myPSSetBaud( hHandle, nAddr, nBaudNum);
    }else {
        qDebug()<<"PSSetBaud失败";
    }
}

int WINAPI as608::PSSetSecurLevel(HANDLE hHandle,int nAddr,int nLevel)
{
    if (myPSSetSecurLevel!= NULL )
    {
        myPSSetSecurLevel( hHandle, nAddr, nLevel);
    }else {
        qDebug()<<"PSSetSecurLevel失败";
    }
}

int WINAPI as608::PSSetPacketSize(HANDLE hHandle,int nAddr,int nSize)
{
    if (myPSSetPacketSize!= NULL )
    {
        myPSSetPacketSize( hHandle, nAddr, nSize);
    }else {
        qDebug()<<"PSSetPacketSize失败";
    }
}

int WINAPI as608::PSUpChar2File(HANDLE hHandle,int nAddr,int iBufferID, const char* pFileName)
{
    if (myPSUpChar2File!= NULL )
    {
        myPSUpChar2File( hHandle, nAddr, iBufferID,  pFileName);
    }else {
        qDebug()<<"PSUpChar2File失败";
    }
}

int WINAPI as608::PSDownCharFromFile(HANDLE hHandle,int nAddr,int iBufferID, const char* pFileName)
{
    if (myPSDownCharFromFile!= NULL )
    {
        myPSDownCharFromFile( hHandle, nAddr, iBufferID,  pFileName);
    }else {
        qDebug()<<"PSDownCharFromFile失败";
    }
}

int WINAPI as608::PSGetRandomData(HANDLE hHandle,int nAddr,unsigned char* pRandom)
{
    if (myPSGetRandomData!= NULL )
    {
        myPSGetRandomData( hHandle, nAddr, pRandom);
    }else {
        qDebug()<<"PSGetRandomData失败";
    }
}

int WINAPI as608::PSSetChipAddr(HANDLE hHandle,int nAddr,unsigned char* pChipAddr)
{
    if (myPSSetChipAddr!= NULL )
    {
        myPSSetChipAddr( hHandle, nAddr, pChipAddr);
    }else {
        qDebug()<<"PSSetChipAddr失败";
    }
}

int WINAPI as608::PSIdentify(HANDLE hHandle,int nAddr,int* iMbAddress)
{
    if (myPSIdentify!= NULL )
    {
        myPSIdentify( hHandle, nAddr, iMbAddress);
    }else {
        qDebug()<<"PSIdentify失败";
    }
}

int WINAPI as608::PSDoUserDefine(HANDLE hHandle,int nAddr,int GPIO,int STATE)
{
    if (myPSDoUserDefine!= NULL )
    {
        myPSDoUserDefine( hHandle, nAddr, GPIO, STATE);
    }else {
        qDebug()<<"PSDoUserDefine失败";
    }
}

int WINAPI as608::PSUpdatOnline(HANDLE hHandle,int nAddr,unsigned char* pImageData, int iLength)
{
    if (myPSUpdatOnline!= NULL )
    {
        myPSUpdatOnline( hHandle, nAddr, pImageData,  iLength);
    }else {
        qDebug()<<"PSUpdatOnline失败";
    }
}

int WINAPI as608::PSBurnCode(HANDLE hHandle,int nAddr,int nType,unsigned char* pImageData, int iLength)
{
    if (myPSBurnCode!= NULL )
    {
        myPSBurnCode( hHandle, nAddr, nType, pImageData,  iLength);
    }else {
        qDebug()<<"PSBurnCode失败";
    }
}

int WINAPI as608::PSPortControl(HANDLE hHandle,int nAddr,BOOL bOpen)
{
    if (myPSPortControl!= NULL )
    {
        myPSPortControl( hHandle, nAddr,bOpen);
    }else {
        qDebug()<<"PSPortControl失败";
    }
}

int WINAPI as608::PSFingerData2BMPData(unsigned char* pFingerData, unsigned char* pBMPData,int* nBMPDataLen)
{
    if (myPSFingerData2BMPData!= NULL )
    {
        myPSFingerData2BMPData( pFingerData,  pBMPData, nBMPDataLen);
    }else {
        qDebug()<<"PSFingerData2BMPData失败";
    }
}

int WINAPI as608::PSShowFingerData(HWND hWnd,unsigned char *pFingerData)
{
    if (myPSShowFingerData!= NULL )
    {
        myPSShowFingerData( hWnd, pFingerData);
    }else {
        qDebug()<<"PSShowFingerData失败";
    }
}

int WINAPI as608::PSReadIndexTable(HANDLE hHandle,int nAddr,int nPage,unsigned char* UserContent)
{
    if (myPSReadIndexTable!= NULL )
    {
        myPSReadIndexTable( hHandle, nAddr, nPage, UserContent);
    }else {
        qDebug()<<"PSReadIndexTable失败";
    }
}

int	WINAPI as608::PS_SB(HANDLE hHandle,int nAddr,unsigned char* pSendData,int iLen,unsigned char* pRecvData,int* pRecvLen,int flag)
{
    if (myPS_SB!= NULL )
    {
        myPS_SB( hHandle, nAddr, pSendData, iLen, pRecvData, pRecvLen, flag);
    }else {
        qDebug()<<"PS_SB失败";
    }
}

