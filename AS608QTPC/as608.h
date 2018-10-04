#ifndef AS608_H
#define AS608_H
#include <QLibrary>
#include <windows.h>
#include <QDebug>
#define PS_MAXWAITTIME 2000
#define DELAY_TIME     150
///////////////////错误返回码////////////////////
#define PS_OK                0x00
#define PS_COMM_ERR          0x01
#define PS_NO_FINGER         0x02
#define PS_GET_IMG_ERR       0x03
#define PS_FP_TOO_DRY        0x04
#define PS_FP_TOO_WET        0x05
#define PS_FP_DISORDER       0x06
#define PS_LITTLE_FEATURE    0x07
#define PS_NOT_MATCH         0x08
#define PS_NOT_SEARCHED      0x09
#define PS_MERGE_ERR         0x0a
#define PS_ADDRESS_OVER      0x0b
#define PS_READ_ERR          0x0c
#define PS_UP_TEMP_ERR       0x0d
#define PS_RECV_ERR          0x0e
#define PS_UP_IMG_ERR        0x0f
#define PS_DEL_TEMP_ERR      0x10
#define PS_CLEAR_TEMP_ERR    0x11
#define PS_SLEEP_ERR         0x12
#define PS_INVALID_PASSWORD  0x13
#define PS_RESET_ERR         0x14
#define PS_INVALID_IMAGE     0x15
#define PS_HANGOVER_UNREMOVE 0X17


///////////////缓冲区//////////////////////////////
#define CHAR_BUFFER_A          0x01
#define CHAR_BUFFER_B          0x02
#define MODEL_BUFFER           0x03

//////////////////串口号////////////////////////
#define COM1                   0x01
#define COM2                   0x02
#define COM3                   0x03

//////////////////波特率////////////////////////
#define BAUD_RATE_9600         0x00
#define BAUD_RATE_19200        0x01
#define BAUD_RATE_38400        0x02
#define BAUD_RATE_57600        0x03   //default
#define BAUD_RATE_115200       0x04

#define MAX_PACKAGE_SIZE_		350   // 数据包最大长度
#define CHAR_LEN_AES1711		1024  // 512->1024 [2009.11.12] AES1711使用1024大小模版
#define CHAR_LEN_NORMAL			512	  // 512 通用版本使用512大小的模版

extern QLibrary SynoAPI;
//==============================================================================//
typedef int WINAPI (*tf_PSGetUSBDevNum)(int*);
typedef int WINAPI (*tf_PSGetUDiskNum)(int* );
typedef int WINAPI (*tf_PSOpenDeviceEx)(HANDLE* , int ,int ,int ,int ,int );
typedef int WINAPI (*tf_PSCloseDeviceEx)(HANDLE );
typedef int WINAPI (*tf_JPSetPackSize)(HANDLE , int );
typedef int WINAPI (*tf_PSAutoOpen)(HANDLE* ,int *, int ,UINT ,int );
typedef int WINAPI (*tf_PSGetImage)(HANDLE ,int );
typedef int WINAPI (*tf_PSGetImage_Enroll)(HANDLE ,int );
typedef int WINAPI (*tf_PSGenChar)(HANDLE ,int ,int );
typedef int WINAPI (*tf_PSMatch)(HANDLE ,int ,int* );
typedef int WINAPI (*tf_PSSearch)(HANDLE ,int ,int , int , int , int *,int *);
typedef int WINAPI (*tf_PSRegModule)(HANDLE ,int );
typedef int WINAPI (*tf_PSStoreChar)(HANDLE ,int ,int , int );
typedef int WINAPI (*tf_PSLoadChar)(HANDLE ,int ,int ,int );
typedef int WINAPI (*tf_PSUpChar)(HANDLE ,int ,int , unsigned char* , int* );
typedef int WINAPI (*tf_PSDownChar)(HANDLE ,int ,int , unsigned char* , int );
typedef int WINAPI (*tf_PSDownChar_Test)(HANDLE ,int ,int , unsigned char* , int ,int ,int ,WORD ,WORD ,int );
typedef int WINAPI (*tf_PSUpImage)(HANDLE ,int ,unsigned char* , int* );
typedef int WINAPI (*tf_PSDownImage)(HANDLE ,int ,unsigned char *, int );
typedef int WINAPI (*tf_PSImgData2BMP)(unsigned char* ,const char* );
typedef int WINAPI (*tf_PSGetImgDataFromBMP)(HANDLE ,const char *,unsigned char *,int *);
typedef int WINAPI (*tf_PSDelChar)(HANDLE ,int ,int ,int );
typedef int WINAPI (*tf_PSEmpty)(HANDLE ,int );
typedef int WINAPI (*tf_PSReadParTable)(HANDLE ,int ,unsigned char* );
typedef int WINAPI (*tf_PSReadInfPage)(HANDLE ,int , unsigned char* );
typedef int WINAPI (*tf_PSHighSpeedSearch)(HANDLE ,int ,int , int , int , int *,int *);
typedef int WINAPI (*tf_PSTemplateNum)(HANDLE ,int ,int *);
typedef int WINAPI (*tf_PSGenBinImage)(HANDLE ,int , int );
typedef int WINAPI (*tf_PSPowerDown)(HANDLE ,int );
typedef int WINAPI (*tf_PSSetPwd)(HANDLE ,int ,unsigned char* );
typedef int WINAPI (*tf_PSVfyPwd)(HANDLE ,int ,unsigned char* );
typedef int WINAPI (*tf_PSReset)(HANDLE ,int );
typedef int WINAPI (*tf_PSReadInfo)(HANDLE ,int ,int ,unsigned char* );
typedef int WINAPI (*tf_PSWriteInfo)(HANDLE ,int ,int ,unsigned char* );
typedef int WINAPI (*tf_PSEnroll)(HANDLE ,int ,int* );
typedef int WINAPI (*tf_PSWriteReg)(HANDLE ,int ,int ,int );
typedef int WINAPI (*tf_PSSetBaud)(HANDLE ,int ,int );
typedef int WINAPI (*tf_PSSetSecurLevel)(HANDLE ,int ,int );
typedef int WINAPI (*tf_PSSetPacketSize)(HANDLE ,int ,int );
typedef int WINAPI (*tf_PSUpChar2File)(HANDLE ,int ,int , const char* );
typedef int WINAPI (*tf_PSDownCharFromFile)(HANDLE ,int ,int , const char* );
typedef int WINAPI (*tf_PSGetRandomData)(HANDLE ,int ,unsigned char* );
typedef int WINAPI (*tf_PSSetChipAddr)(HANDLE ,int ,unsigned char* );
typedef int WINAPI (*tf_PSIdentify)(HANDLE ,int ,int *);
typedef int WINAPI (*tf_PSDoUserDefine)(HANDLE ,int ,int ,int );
typedef int WINAPI (*tf_PSUpdatOnline)(HANDLE ,int ,unsigned char *, int );
typedef int WINAPI (*tf_PSBurnCode)(HANDLE ,int ,int ,unsigned char *, int );
typedef int WINAPI (*tf_PSPortControl)(HANDLE ,int ,BOOL );
typedef int WINAPI (*tf_PSFingerData2BMPData)(unsigned char *, unsigned char *,int* );
typedef int WINAPI (*tf_PSShowFingerData)(HWND ,unsigned char *);
typedef int WINAPI (*tf_PSReadIndexTable)(HANDLE ,int ,int ,unsigned char* );
typedef int WINAPI (*tf_PS_SB)(HANDLE ,int ,unsigned char *,int ,unsigned char *,int *,int );
class as608
{
public:
    as608();
    tf_PSGetUSBDevNum myPSGetUSBDevNum = (tf_PSGetUSBDevNum)SynoAPI.resolve("PSGetUSBDevNum");
    tf_PSGetUDiskNum myPSGetUDiskNum = (tf_PSGetUDiskNum)SynoAPI.resolve("PSGetUDiskNum");
    tf_PSOpenDeviceEx myPSOpenDeviceEx = (tf_PSOpenDeviceEx)SynoAPI.resolve("PSOpenDeviceEx");
    tf_PSCloseDeviceEx myPSCloseDeviceEx = (tf_PSCloseDeviceEx)SynoAPI.resolve("PSCloseDeviceEx");
    tf_JPSetPackSize myJPSetPackSize = (tf_JPSetPackSize)SynoAPI.resolve("JPSetPackSize");
    tf_PSAutoOpen myPSAutoOpen = (tf_PSAutoOpen)SynoAPI.resolve("PSAutoOpen");
    tf_PSGetImage myPSGetImage = (tf_PSGetImage)SynoAPI.resolve("PSGetImage");
    tf_PSGetImage_Enroll myPSGetImage_Enroll = (tf_PSGetImage_Enroll)SynoAPI.resolve("PSGetImage_Enroll");
    tf_PSGenChar myPSGenChar = (tf_PSGenChar)SynoAPI.resolve("PSGenChar");
    tf_PSMatch myPSMatch = (tf_PSMatch)SynoAPI.resolve("PSMatch");
    tf_PSSearch myPSSearch = (tf_PSSearch)SynoAPI.resolve("PSSearch");
    tf_PSRegModule myPSRegModule = (tf_PSRegModule)SynoAPI.resolve("PSRegModule");
    tf_PSStoreChar myPSStoreChar = (tf_PSStoreChar)SynoAPI.resolve("PSStoreChar");
    tf_PSLoadChar myPSLoadChar = (tf_PSLoadChar)SynoAPI.resolve("PSLoadChar");
    tf_PSUpChar myPSUpChar = (tf_PSUpChar)SynoAPI.resolve("PSUpChar");
    tf_PSDownChar myPSDownChar = (tf_PSDownChar)SynoAPI.resolve("PSDownChar");
    tf_PSDownChar_Test myPSDownChar_Test = (tf_PSDownChar_Test)SynoAPI.resolve("PSDownChar_Test");
    tf_PSUpImage myPSUpImage = (tf_PSUpImage)SynoAPI.resolve("PSUpImage");
    tf_PSDownImage myPSDownImage = (tf_PSDownImage)SynoAPI.resolve("PSDownImage");
    tf_PSImgData2BMP myPSImgData2BMP = (tf_PSImgData2BMP)SynoAPI.resolve("PSImgData2BMP");
    tf_PSGetImgDataFromBMP myPSGetImgDataFromBMP = (tf_PSGetImgDataFromBMP)SynoAPI.resolve("PSGetImgDataFromBMP");
    tf_PSDelChar myPSDelChar = (tf_PSDelChar)SynoAPI.resolve("PSDelChar");
    tf_PSEmpty myPSEmpty = (tf_PSEmpty)SynoAPI.resolve("PSEmpty");
    tf_PSReadParTable myPSReadParTable = (tf_PSReadParTable)SynoAPI.resolve("PSReadParTable");
    tf_PSReadInfPage myPSReadInfPage = (tf_PSReadInfPage)SynoAPI.resolve("PSReadInfPage");
    tf_PSHighSpeedSearch myPSHighSpeedSearch = (tf_PSHighSpeedSearch)SynoAPI.resolve("PSHighSpeedSearch");
    tf_PSTemplateNum myPSTemplateNum = (tf_PSTemplateNum)SynoAPI.resolve("PSTemplateNum");
    tf_PSGenBinImage myPSGenBinImage = (tf_PSGenBinImage)SynoAPI.resolve("PSGenBinImage");
    tf_PSPowerDown myPSPowerDown = (tf_PSPowerDown)SynoAPI.resolve("PSPowerDown");
    tf_PSSetPwd myPSSetPwd = (tf_PSSetPwd)SynoAPI.resolve("PSSetPwd");
    tf_PSVfyPwd myPSVfyPwd = (tf_PSVfyPwd)SynoAPI.resolve("PSVfyPwd");
    tf_PSReset myPSReset = (tf_PSReset)SynoAPI.resolve("PSReset");
    tf_PSReadInfo myPSReadInfo = (tf_PSReadInfo)SynoAPI.resolve("PSReadInfo");
    tf_PSWriteInfo myPSWriteInfo = (tf_PSWriteInfo)SynoAPI.resolve("PSWriteInfo");
    tf_PSEnroll myPSEnroll = (tf_PSEnroll)SynoAPI.resolve("PSEnroll");
    tf_PSWriteReg myPSWriteReg = (tf_PSWriteReg)SynoAPI.resolve("PSWriteReg");
    tf_PSSetBaud myPSSetBaud = (tf_PSSetBaud)SynoAPI.resolve("PSSetBaud");
    tf_PSSetSecurLevel myPSSetSecurLevel = (tf_PSSetSecurLevel)SynoAPI.resolve("PSSetSecurLevel");
    tf_PSSetPacketSize myPSSetPacketSize = (tf_PSSetPacketSize)SynoAPI.resolve("PSSetPacketSize");
    tf_PSUpChar2File myPSUpChar2File = (tf_PSUpChar2File)SynoAPI.resolve("PSUpChar2File");
    tf_PSDownCharFromFile myPSDownCharFromFile = (tf_PSDownCharFromFile)SynoAPI.resolve("PSDownCharFromFile");
    tf_PSGetRandomData myPSGetRandomData = (tf_PSGetRandomData)SynoAPI.resolve("PSGetRandomData");
    tf_PSSetChipAddr myPSSetChipAddr = (tf_PSSetChipAddr)SynoAPI.resolve("PSSetChipAddr");
    tf_PSIdentify myPSIdentify = (tf_PSIdentify)SynoAPI.resolve("PSIdentify");
    tf_PSDoUserDefine myPSDoUserDefine = (tf_PSDoUserDefine)SynoAPI.resolve("PSDoUserDefine");
    tf_PSUpdatOnline myPSUpdatOnline = (tf_PSUpdatOnline)SynoAPI.resolve("PSUpdatOnline");
    tf_PSBurnCode myPSBurnCode = (tf_PSBurnCode)SynoAPI.resolve("PSBurnCode");
    tf_PSPortControl myPSPortControl = (tf_PSPortControl)SynoAPI.resolve("PSPortControl");
    tf_PSFingerData2BMPData myPSFingerData2BMPData = (tf_PSFingerData2BMPData)SynoAPI.resolve("PSFingerData2BMPData");
    tf_PSShowFingerData myPSShowFingerData = (tf_PSShowFingerData)SynoAPI.resolve("PSShowFingerData");
    tf_PSReadIndexTable myPSReadIndexTable = (tf_PSReadIndexTable)SynoAPI.resolve("PSReadIndexTable");
    tf_PS_SB myPS_SB = (tf_PS_SB)SynoAPI.resolve("PS_SB");

    //==============================================================================//
    int WINAPI	PSGetUSBDevNum(int* iNums);//获取 FG_USB 设备数
    int WINAPI	PSGetUDiskNum(int* iNums); //获取 UDISK 设备数
    int WINAPI	PSOpenDeviceEx(HANDLE* pHandle, int nDeviceType,int iCom=1,int iBaud=1,int nPackageSize=2,int iDevNum=0);
    int WINAPI	PSCloseDeviceEx(HANDLE hHandle);
//	int WINAPI	PSGetPacketSize(HANDLE);
    int WINAPI  JPSetPackSize(HANDLE hHandle=NULL, int nPackSize=2);
    int WINAPI	PSAutoOpen(HANDLE* pHandle,int *type, int nAddr=0xFFFFFFFF,UINT uPwd=0x00,int bVfy=1);
    //==============================================================================//
    ///////////////////////////////////////////////
    //////             指令                  //////
    ///////////////////////////////////////////////
    //检测手指并录取图像
    int WINAPI	PSGetImage(HANDLE hHandle,int nAddr);
    int WINAPI	PSGetImage_Enroll(HANDLE hHandle,int nAddr);	// 0x29 注册时获取图像	//2010.6.25 blue

    //根据原始图像生成指纹特征
    int WINAPI	PSGenChar(HANDLE hHandle,int nAddr,int iBufferID);

    //精确比对CharBufferA与CharBufferB中的特征文件
    int WINAPI	PSMatch(HANDLE hHandle,int nAddr,int* iScore);

    //以CharBufferA或CharBufferB中的特征文件搜索整个或部分指纹库
//	int WINAPI	PSSearch(HANDLE hHandle,int nAddr,int iBufferID, int iStartPage, int iPageNum, int *iMbAddress);
    int WINAPI	PSSearch(HANDLE hHandle,int nAddr,int iBufferID, int iStartPage, int iPageNum, int *iMbAddress,int *iscore=NULL);

    //将CharBufferA与CharBufferB中的特征文件合并生成模板存于ModelBuffer
    int	WINAPI	PSRegModule(HANDLE hHandle,int nAddr);

    //将ModelBuffer中的文件储存到flash指纹库中
    int WINAPI	PSStoreChar(HANDLE hHandle,int nAddr,int iBufferID, int iPageID);

    //从flash指纹库中读取一个模板到ModelBuffer
    int WINAPI	PSLoadChar(HANDLE hHandle,int nAddr,int iBufferID,int iPageID);

    //将特征缓冲区中的文件上传给上位机
    int WINAPI	PSUpChar(HANDLE hHandle,int nAddr,int iBufferID, unsigned char* pTemplet, int* iTempletLength);

    //从上位机下载一个特征文件到特征缓冲区
    int WINAPI	PSDownChar(HANDLE hHandle,int nAddr,int iBufferID, unsigned char* pTemplet, int iTempletLength);
    int WINAPI  PSDownChar_Test(HANDLE hHandle,int nAddr,int iBufferID, unsigned char* pTemplet, int iTempletLength,int nAddr1,int ipack=MAX_PACKAGE_SIZE_,WORD whead=0xEF01,WORD wCheck=0x0000,int iErr=0);

    //上传原始图像
    int WINAPI	PSUpImage(HANDLE hHandle,int nAddr,unsigned char* pImageData, int* iImageLength);

    //下载原始图像
    int WINAPI	PSDownImage(HANDLE hHandle,int nAddr,unsigned char *pImageData, int iLength);

    //上传原始图像
    int WINAPI	PSImgData2BMP(unsigned char* pImgData,const char* pImageFile);

    //下载原始图像
    int WINAPI	PSGetImgDataFromBMP(HANDLE hHandle,const char *pImageFile,unsigned char *pImageData,int *pnImageLen);

    //删除flash指纹库中的一个特征文件
    int WINAPI	PSDelChar(HANDLE hHandle,int nAddr,int iStartPageID,int nDelPageNum);

    //清空flash指纹库
    int WINAPI	PSEmpty(HANDLE hHandle,int nAddr);

    //读参数表
    int WINAPI	PSReadParTable(HANDLE hHandle,int nAddr,unsigned char* pParTable);

    //++读Flash
    int WINAPI	PSReadInfPage(HANDLE hHandle,int nAddr, unsigned char* pInf);

    //++高速搜索
//	int WINAPI	PSHighSpeedSearch(HANDLE hHandle,int nAddr,int iBufferID, int iStartPage, int iPageNum, int *iMbAddress);
    int WINAPI	PSHighSpeedSearch(HANDLE hHandle,int nAddr,int iBufferID, int iStartPage, int iPageNum, int *iMbAddress,int *iscore=NULL);

    //++读有效模板个数
    int WINAPI	PSTemplateNum(HANDLE hHandle,int nAddr,int *iMbNum);

    //++指纹图细化
    int WINAPI	PSGenBinImage(HANDLE hHandle,int nAddr, int nImgType);

    //休眠指令
    int WINAPI	PSPowerDown(HANDLE hHandle,int nAddr);

    //设置设备握手口令
    int WINAPI	PSSetPwd(HANDLE hHandle,int nAddr,unsigned char* pPassword);

    //验证设备握手口令
    int WINAPI	PSVfyPwd(HANDLE hHandle,int nAddr,unsigned char* pPassword);

    //系统复位，进入上电初始状态
    int WINAPI	PSReset(HANDLE hHandle,int nAddr);

    //读记事本
    int WINAPI	PSReadInfo(HANDLE hHandle,int nAddr,int nPage,unsigned char* UserContent);

    //写记事本
    int WINAPI	PSWriteInfo(HANDLE hHandle,int nAddr,int nPage,unsigned char* UserContent);

    //++注册模板
    int WINAPI	PSEnroll(HANDLE hHandle,int nAddr,int* nID);

    //++写模块寄存器
    int WINAPI	PSWriteReg(HANDLE hHandle,int nAddr,int iRegAddr,int iRegValue);
    //写模块寄存器－波特率设置
    int WINAPI	PSSetBaud(HANDLE hHandle,int nAddr,int nBaudNum);
    //写模块寄存器－安全等级设置
    int WINAPI	PSSetSecurLevel(HANDLE hHandle,int nAddr,int nLevel);
    //写模块寄存器－数据包大小设置
    int WINAPI	PSSetPacketSize(HANDLE hHandle,int nAddr,int nSize);

    int WINAPI	PSUpChar2File(HANDLE hHandle,int nAddr,int iBufferID, const char* pFileName);
    int WINAPI	PSDownCharFromFile(HANDLE hHandle,int nAddr,int iBufferID, const char* pFileName);

    //获取随机数
    int WINAPI	PSGetRandomData(HANDLE hHandle,int nAddr,unsigned char* pRandom);

    //设置芯片地址
    int WINAPI	PSSetChipAddr(HANDLE hHandle,int nAddr,unsigned char* pChipAddr);

    //++自动验证指纹
    int WINAPI	PSIdentify(HANDLE hHandle,int nAddr,int *iMbAddress);

    int WINAPI	PSDoUserDefine(HANDLE hHandle,int nAddr,int GPIO,int STATE);

    ///////////////////////////////////////////////////////////////////////++2008-12-12
    int WINAPI	PSUpdatOnline(HANDLE hHandle,int nAddr,unsigned char *pImageData, int iLength);
    int WINAPI	PSBurnCode(HANDLE hHandle,int nAddr,int nType,unsigned char *pImageData, int iLength);
    int WINAPI	PSPortControl(HANDLE hHandle,int nAddr,BOOL bOpen);
    int WINAPI	PSFingerData2BMPData(unsigned char *pFingerData, unsigned char *pBMPData,int* nBMPDataLen);
    int WINAPI	PSShowFingerData(HWND hWnd,unsigned char *pFingerData);
    ///////////////////////////////////////////////////////////////////////++

    //读模版索引表	nPage,0,1,2,3对应模版从0-256，256-512，512-768，768-1024
    int WINAPI	PSReadIndexTable(HANDLE hHandle,int nAddr,int nPage,unsigned char* UserContent);

    //自定义发送包	2009-03-04
    //pRecvData=NUll时，表示不分解获取数据
    int	WINAPI	PS_SB(HANDLE hHandle,int nAddr,unsigned char *pSendData,int iLen,unsigned char *pRecvData,int *pRecvLen,int flag=1);


};

#endif // AS608_H
