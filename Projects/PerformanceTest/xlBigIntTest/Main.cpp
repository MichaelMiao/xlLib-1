//------------------------------------------------------------------------------
//
//    Copyright (C) Streamlet. All rights reserved.
//
//    File Name:   Main.cpp
//    Author:      Streamlet
//    Create Time: 2010-08-08
//    Description: 
//
//    Version history:
//
//
//
//------------------------------------------------------------------------------


#include "../PerformanceTest.h"
#include <xl/Math/xlBigInt.h>
#include <wchar.h>

#define P_512   L"BF273099C31081FA8F32819C4D5C219579A9430B5B594FB3825F5929B77D1813"
#define Q_512   L"D91F81D4F71454D277E31C9C0B487D3A4CC490792ECCEC81CAA84603AE75716B"
#define N_512   L"A21FBEE2FD67561826B9562CEE35334692D5049EA832ECEB89E2191E1F0BAFDAD9262266E5083D6BE0E7F853E4369B84ABCE72E773312914D4820B2FD39872F1"
#define D_512   L"83711584574AC6A48210D56B4C1DD9DAA80508DFD122A8AF36751744328B7920BCD5EAA3DBB1CE6B8FD259B7E76A8EE5E2EA798EE9BE2FD9F2AF308EAF734A59"
#define E_512   L"10001"

#define P_1024  L"D840E5A3749A9149421578A8F5D9D6E1C8C7D22A2DA83B81C78EEEBD99834007C1270BDC1422324B5374A99C5A1082F32A981EEEB6785426FF65BA2D85780F4B"
#define Q_1024  L"BE4596D7818C4313F457A19EF8BABC1F30EE43EDF4180F82457AFD2E784209DDAF4E813B66C523E7ED0B3B8CC8849659F4546F2CFE642133C3C8C4E00FBBD1EB"
#define N_1024  L"A0BAF3594816F7F5D1340C6E6ADF482CD564FCB9D503F9A42029E532D6A89E6BA2F9BC0B47AF5D942745041699B4C06CFD369E360C38187D01C1B785A8E52FBEE350B4176D8587D96F97F502E7CC1E65010CD3FFD39739C1A97736E893E532AF3882640880416B7CF0C16752EEA583807F087E1D6E94CDEDF1CE66F91A7B44D9"
#define D_1024  L"430BF93B031161BA0EDC915AF605D20BB1B080A3DC31DE4F1283A7723F8CF3189F516199AAFB8223AD05E320B2596DF388E4E1B655FE88688CF50BE31B830F18FE115485565E10ACFF03DB5E275B7E2FE9C7CB4BFD2955498F19203098EF4AA1F16B39B62CAF5935F5EA3DABC5CE0B1F07366035B80D2815AD5B52D9322D8769"
#define E_1024  L"10001"

#define P_2048  L"83836EC1603C4CF01E29DEC07179B0E25A275783CA1E80009B695C6B2DDEBAF9B1E0C65C00F86D594C24F5E41D37AAECE62DDC4D667266E8A28CDA9584E466A9032DC544DD3417FEA5C4D57A1A9A639B9835069F555292D128083FE337E68E31B8D69CCCCCA80092284E71BFB950DADE37AE531D8CBAD5A1EEC16397B256C43B"
#define Q_2048  L"977537C427DC631986871CE1A2C4B05AB652B48286CCE1B80AE0C8CB5769D61B37ED463AF3CC284CDBDAD7FE268881E8CD56EB20147EF30868F903C7B93E971BA6BF1109EA7D4FA748D86D4C870DD93DC56E0793B9554F9F4F976B865F5944D6670A1DA11F67834174E51C11779C9B4BDE27AC87707CDC4040D28D55534ED363"
#define N_2048  L"4DCEBE0BB00B226702D9AB9BBCFC3991D37E0E0FB335FFE72557C7B14C5727FEECEDD7AD4D39820057B60897180DE3F599CE4148CC073B1140D3E4D20B3790E481C0EE93DE6FF6FC5F8A9FF785D5DEC4B4702F89042F4F929F8FD3A3343C9F80834E329570DE93EFB613C5C52A42BBBA731F5B78A0918D20A77D3C34E186223E21D6E73FC3BE3F04D2CA81DB02B038C712E288F34A3FD435F3F0CB15532AA019EECF62A2C1582D3490A5F92E3E78B00607E24602B950142A54108F645E1B3A889EF3E0FFB8ED20379D9CDBAF0DE9C56E911DAB670326690932A320415ACA458B839E8EAB3F202697B2282410868A31485ECC00976E12E532FA33AA4D664483D1"
#define D_2048  L"26B732B55A19903AB59E5DD79687E2957F2900122BD838C7693B6E6FF84E7DE6493A67D121D5F5ABF9F8E7F956CCC29B58B6DAA14074709DBB26347B977D44A98F2ED307DCECD576EA8B6DE19A44BB1E21B298D492B27FE3B365BBA73FBCD298FDBD114A6EE931AF5B6827465E2AEA8271FA2E67AD6DFF4D3A4A0485439A9CBAC50A1E270CBAEA946D71E1E9BE2C0355F6B0CB48971FC0003D7D2897DED6172726406DF25D0F2BA07ECE0049442E3F88F2D1BAC4C44E1A579A92F857553F0DED6BA4DF5B000DF95EF436D67D0030F3A75A002EECC54197F3B34A9AFF299B6033A493B661F54D17D07DA4DE86113175A23227C67CDC4F160FA3632AB89C1B37E9"
#define E_2048  L"10001"

int main()
{
    using namespace xl;

    BigInt p, q, n, d, e;
    BigInt plain, encoded, decoded;

    SECTION_BEGIN(512BitRSA);
    p.FromString(P_512, 16);
    q.FromString(Q_512, 16);
    n.FromString(N_512, 16);
    d.FromString(D_512, 16);
    e.FromString(E_512, 16);
    wprintf(L"P = %s\n", (const wchar_t *)p.ToString(16));
    wprintf(L"Q = %s\n", (const wchar_t *)q.ToString(16));
    wprintf(L"N = %s\n", (const wchar_t *)n.ToString(16));
    wprintf(L"D = %s\n", (const wchar_t *)d.ToString(16));
    wprintf(L"E = %s\n", (const wchar_t *)e.ToString(16));
    plain = 12345;
    encoded = 0;
    decoded = 0;
    PERFORMANCE_TEST_BEGIN(512BitRSA);
    encoded = plain.ExpMod(d, n);
    decoded = encoded.ExpMod(e, n);
    PERFORMANCE_TEST_END(512BitRSA);
    wprintf(L"Plain   = %s\n", (const wchar_t *)plain.ToString(16));
    wprintf(L"Encoded = %s\n", (const wchar_t *)encoded.ToString(16));
    wprintf(L"Decoded = %s\n", (const wchar_t *)decoded.ToString(16));
    SECTION_END();

    SECTION_BEGIN(1024BitRSA);
    p.FromString(P_1024, 16);
    q.FromString(Q_1024, 16);
    n.FromString(N_1024, 16);
    d.FromString(D_1024, 16);
    e.FromString(E_1024, 16);
    wprintf(L"P = %s\n", (const wchar_t *)p.ToString(16));
    wprintf(L"Q = %s\n", (const wchar_t *)q.ToString(16));
    wprintf(L"N = %s\n", (const wchar_t *)n.ToString(16));
    wprintf(L"D = %s\n", (const wchar_t *)d.ToString(16));
    wprintf(L"E = %s\n", (const wchar_t *)e.ToString(16));
    plain = 12345;
    encoded = 0;
    decoded = 0;
    PERFORMANCE_TEST_BEGIN(1024BitRSA);
    encoded = plain.ExpMod(d, n);
    decoded = encoded.ExpMod(e, n);
    PERFORMANCE_TEST_END(1024BitRSA);
    wprintf(L"Plain   = %s\n", (const wchar_t *)plain.ToString(16));
    wprintf(L"Encoded = %s\n", (const wchar_t *)encoded.ToString(16));
    wprintf(L"Decoded = %s\n", (const wchar_t *)decoded.ToString(16));
    SECTION_END();

    SECTION_BEGIN(2048BitRSA);
    p.FromString(P_2048, 16);
    q.FromString(Q_2048, 16);
    n.FromString(N_2048, 16);
    d.FromString(D_2048, 16);
    e.FromString(E_2048, 16);
    wprintf(L"P = %s\n", (const wchar_t *)p.ToString(16));
    wprintf(L"Q = %s\n", (const wchar_t *)q.ToString(16));
    wprintf(L"N = %s\n", (const wchar_t *)n.ToString(16));
    wprintf(L"D = %s\n", (const wchar_t *)d.ToString(16));
    wprintf(L"E = %s\n", (const wchar_t *)e.ToString(16));
    plain = 12345;
    encoded = 0;
    decoded = 0;
    PERFORMANCE_TEST_BEGIN(2048BitRSA);
    encoded = plain.ExpMod(d, n);
    decoded = encoded.ExpMod(e, n);
    PERFORMANCE_TEST_END(2048BitRSA);
    wprintf(L"Plain   = %s\n", (const wchar_t *)plain.ToString(16));
    wprintf(L"Encoded = %s\n", (const wchar_t *)encoded.ToString(16));
    wprintf(L"Decoded = %s\n", (const wchar_t *)decoded.ToString(16));
    SECTION_END();

    return 0;
}
