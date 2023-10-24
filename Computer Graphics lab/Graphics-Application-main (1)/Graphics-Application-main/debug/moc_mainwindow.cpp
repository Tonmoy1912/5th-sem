/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "Mouse_Pressed",
    "",
    "showMousePosition",
    "QPoint&",
    "pos",
    "on_show_axes_clicked",
    "on_set_point1_clicked",
    "on_set_point2_clicked",
    "on_pushButton_clicked",
    "on_pushButton_shGrid_clicked",
    "on_spinBox_valueChanged",
    "arg1",
    "on_DrawDDALine_clicked",
    "on_DrawBresenhamLine_clicked",
    "on_polarCircle_clicked",
    "on_bresenhamMidpointCircle_clicked",
    "on_midpointEllipse_clicked",
    "on_polarEllipse_clicked",
    "on_setVertex_clicked",
    "on_clearVertex_clicked",
    "on_floodFill_clicked",
    "on_boundaryFill_clicked",
    "drawDDALine",
    "r",
    "g",
    "b",
    "delay",
    "initEdgeTable",
    "on_scanLineFill_clicked",
    "storeEdgeInTable",
    "x1",
    "y1",
    "x2",
    "y2",
    "boundary_fill_8point",
    "x",
    "y",
    "QRgb",
    "edgecolor",
    "boundary_fill_4point",
    "flood_fill_4point",
    "flood_fill_8point",
    "poly_draw",
    "std::vector<std::pair<int,int>>",
    "vlist",
    "point",
    "draw_Window",
    "cohenSutherlandClip",
    "computeCode",
    "xa",
    "ya",
    "drawLineByStoringPoints",
    "suthHodgClip",
    "clip",
    "y_intersect",
    "x3",
    "y3",
    "x4",
    "y4",
    "x_intersect",
    "on_translation_clicked",
    "on_scaling_clicked",
    "on_shearing_clicked",
    "on_rotation_clicked",
    "on_reflection_clicked",
    "on_setCorner_2_clicked",
    "on_setCorner_1_clicked",
    "on_drawAndStore_clicked",
    "on_lineClip_clicked",
    "on_polygonClip_clicked",
    "on_setControlPoint_clicked",
    "on_clearControlPoint_clicked",
    "on_drawBezierCurve_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[148];
    char stringdata0[11];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[18];
    char stringdata4[8];
    char stringdata5[4];
    char stringdata6[21];
    char stringdata7[22];
    char stringdata8[22];
    char stringdata9[22];
    char stringdata10[29];
    char stringdata11[24];
    char stringdata12[5];
    char stringdata13[23];
    char stringdata14[29];
    char stringdata15[23];
    char stringdata16[35];
    char stringdata17[27];
    char stringdata18[24];
    char stringdata19[21];
    char stringdata20[23];
    char stringdata21[21];
    char stringdata22[24];
    char stringdata23[12];
    char stringdata24[2];
    char stringdata25[2];
    char stringdata26[2];
    char stringdata27[6];
    char stringdata28[14];
    char stringdata29[24];
    char stringdata30[17];
    char stringdata31[3];
    char stringdata32[3];
    char stringdata33[3];
    char stringdata34[3];
    char stringdata35[21];
    char stringdata36[2];
    char stringdata37[2];
    char stringdata38[5];
    char stringdata39[10];
    char stringdata40[21];
    char stringdata41[18];
    char stringdata42[18];
    char stringdata43[10];
    char stringdata44[32];
    char stringdata45[6];
    char stringdata46[6];
    char stringdata47[12];
    char stringdata48[20];
    char stringdata49[12];
    char stringdata50[3];
    char stringdata51[3];
    char stringdata52[24];
    char stringdata53[13];
    char stringdata54[5];
    char stringdata55[12];
    char stringdata56[3];
    char stringdata57[3];
    char stringdata58[3];
    char stringdata59[3];
    char stringdata60[12];
    char stringdata61[23];
    char stringdata62[19];
    char stringdata63[20];
    char stringdata64[20];
    char stringdata65[22];
    char stringdata66[23];
    char stringdata67[23];
    char stringdata68[24];
    char stringdata69[20];
    char stringdata70[23];
    char stringdata71[27];
    char stringdata72[29];
    char stringdata73[27];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 13),  // "Mouse_Pressed"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 17),  // "showMousePosition"
        QT_MOC_LITERAL(44, 7),  // "QPoint&"
        QT_MOC_LITERAL(52, 3),  // "pos"
        QT_MOC_LITERAL(56, 20),  // "on_show_axes_clicked"
        QT_MOC_LITERAL(77, 21),  // "on_set_point1_clicked"
        QT_MOC_LITERAL(99, 21),  // "on_set_point2_clicked"
        QT_MOC_LITERAL(121, 21),  // "on_pushButton_clicked"
        QT_MOC_LITERAL(143, 28),  // "on_pushButton_shGrid_clicked"
        QT_MOC_LITERAL(172, 23),  // "on_spinBox_valueChanged"
        QT_MOC_LITERAL(196, 4),  // "arg1"
        QT_MOC_LITERAL(201, 22),  // "on_DrawDDALine_clicked"
        QT_MOC_LITERAL(224, 28),  // "on_DrawBresenhamLine_clicked"
        QT_MOC_LITERAL(253, 22),  // "on_polarCircle_clicked"
        QT_MOC_LITERAL(276, 34),  // "on_bresenhamMidpointCircle_cl..."
        QT_MOC_LITERAL(311, 26),  // "on_midpointEllipse_clicked"
        QT_MOC_LITERAL(338, 23),  // "on_polarEllipse_clicked"
        QT_MOC_LITERAL(362, 20),  // "on_setVertex_clicked"
        QT_MOC_LITERAL(383, 22),  // "on_clearVertex_clicked"
        QT_MOC_LITERAL(406, 20),  // "on_floodFill_clicked"
        QT_MOC_LITERAL(427, 23),  // "on_boundaryFill_clicked"
        QT_MOC_LITERAL(451, 11),  // "drawDDALine"
        QT_MOC_LITERAL(463, 1),  // "r"
        QT_MOC_LITERAL(465, 1),  // "g"
        QT_MOC_LITERAL(467, 1),  // "b"
        QT_MOC_LITERAL(469, 5),  // "delay"
        QT_MOC_LITERAL(475, 13),  // "initEdgeTable"
        QT_MOC_LITERAL(489, 23),  // "on_scanLineFill_clicked"
        QT_MOC_LITERAL(513, 16),  // "storeEdgeInTable"
        QT_MOC_LITERAL(530, 2),  // "x1"
        QT_MOC_LITERAL(533, 2),  // "y1"
        QT_MOC_LITERAL(536, 2),  // "x2"
        QT_MOC_LITERAL(539, 2),  // "y2"
        QT_MOC_LITERAL(542, 20),  // "boundary_fill_8point"
        QT_MOC_LITERAL(563, 1),  // "x"
        QT_MOC_LITERAL(565, 1),  // "y"
        QT_MOC_LITERAL(567, 4),  // "QRgb"
        QT_MOC_LITERAL(572, 9),  // "edgecolor"
        QT_MOC_LITERAL(582, 20),  // "boundary_fill_4point"
        QT_MOC_LITERAL(603, 17),  // "flood_fill_4point"
        QT_MOC_LITERAL(621, 17),  // "flood_fill_8point"
        QT_MOC_LITERAL(639, 9),  // "poly_draw"
        QT_MOC_LITERAL(649, 31),  // "std::vector<std::pair<int,int>>"
        QT_MOC_LITERAL(681, 5),  // "vlist"
        QT_MOC_LITERAL(687, 5),  // "point"
        QT_MOC_LITERAL(693, 11),  // "draw_Window"
        QT_MOC_LITERAL(705, 19),  // "cohenSutherlandClip"
        QT_MOC_LITERAL(725, 11),  // "computeCode"
        QT_MOC_LITERAL(737, 2),  // "xa"
        QT_MOC_LITERAL(740, 2),  // "ya"
        QT_MOC_LITERAL(743, 23),  // "drawLineByStoringPoints"
        QT_MOC_LITERAL(767, 12),  // "suthHodgClip"
        QT_MOC_LITERAL(780, 4),  // "clip"
        QT_MOC_LITERAL(785, 11),  // "y_intersect"
        QT_MOC_LITERAL(797, 2),  // "x3"
        QT_MOC_LITERAL(800, 2),  // "y3"
        QT_MOC_LITERAL(803, 2),  // "x4"
        QT_MOC_LITERAL(806, 2),  // "y4"
        QT_MOC_LITERAL(809, 11),  // "x_intersect"
        QT_MOC_LITERAL(821, 22),  // "on_translation_clicked"
        QT_MOC_LITERAL(844, 18),  // "on_scaling_clicked"
        QT_MOC_LITERAL(863, 19),  // "on_shearing_clicked"
        QT_MOC_LITERAL(883, 19),  // "on_rotation_clicked"
        QT_MOC_LITERAL(903, 21),  // "on_reflection_clicked"
        QT_MOC_LITERAL(925, 22),  // "on_setCorner_2_clicked"
        QT_MOC_LITERAL(948, 22),  // "on_setCorner_1_clicked"
        QT_MOC_LITERAL(971, 23),  // "on_drawAndStore_clicked"
        QT_MOC_LITERAL(995, 19),  // "on_lineClip_clicked"
        QT_MOC_LITERAL(1015, 22),  // "on_polygonClip_clicked"
        QT_MOC_LITERAL(1038, 26),  // "on_setControlPoint_clicked"
        QT_MOC_LITERAL(1065, 28),  // "on_clearControlPoint_clicked"
        QT_MOC_LITERAL(1094, 26)   // "on_drawBezierCurve_clicked"
    },
    "MainWindow",
    "Mouse_Pressed",
    "",
    "showMousePosition",
    "QPoint&",
    "pos",
    "on_show_axes_clicked",
    "on_set_point1_clicked",
    "on_set_point2_clicked",
    "on_pushButton_clicked",
    "on_pushButton_shGrid_clicked",
    "on_spinBox_valueChanged",
    "arg1",
    "on_DrawDDALine_clicked",
    "on_DrawBresenhamLine_clicked",
    "on_polarCircle_clicked",
    "on_bresenhamMidpointCircle_clicked",
    "on_midpointEllipse_clicked",
    "on_polarEllipse_clicked",
    "on_setVertex_clicked",
    "on_clearVertex_clicked",
    "on_floodFill_clicked",
    "on_boundaryFill_clicked",
    "drawDDALine",
    "r",
    "g",
    "b",
    "delay",
    "initEdgeTable",
    "on_scanLineFill_clicked",
    "storeEdgeInTable",
    "x1",
    "y1",
    "x2",
    "y2",
    "boundary_fill_8point",
    "x",
    "y",
    "QRgb",
    "edgecolor",
    "boundary_fill_4point",
    "flood_fill_4point",
    "flood_fill_8point",
    "poly_draw",
    "std::vector<std::pair<int,int>>",
    "vlist",
    "point",
    "draw_Window",
    "cohenSutherlandClip",
    "computeCode",
    "xa",
    "ya",
    "drawLineByStoringPoints",
    "suthHodgClip",
    "clip",
    "y_intersect",
    "x3",
    "y3",
    "x4",
    "y4",
    "x_intersect",
    "on_translation_clicked",
    "on_scaling_clicked",
    "on_shearing_clicked",
    "on_rotation_clicked",
    "on_reflection_clicked",
    "on_setCorner_2_clicked",
    "on_setCorner_1_clicked",
    "on_drawAndStore_clicked",
    "on_lineClip_clicked",
    "on_polygonClip_clicked",
    "on_setControlPoint_clicked",
    "on_clearControlPoint_clicked",
    "on_drawBezierCurve_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      50,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  314,    2, 0x0a,    1 /* Public */,
       3,    1,  315,    2, 0x0a,    2 /* Public */,
       6,    0,  318,    2, 0x08,    4 /* Private */,
       7,    0,  319,    2, 0x08,    5 /* Private */,
       8,    0,  320,    2, 0x08,    6 /* Private */,
       9,    0,  321,    2, 0x08,    7 /* Private */,
      10,    0,  322,    2, 0x08,    8 /* Private */,
      11,    1,  323,    2, 0x08,    9 /* Private */,
      13,    0,  326,    2, 0x08,   11 /* Private */,
      14,    0,  327,    2, 0x08,   12 /* Private */,
      15,    0,  328,    2, 0x08,   13 /* Private */,
      16,    0,  329,    2, 0x08,   14 /* Private */,
      17,    0,  330,    2, 0x08,   15 /* Private */,
      18,    0,  331,    2, 0x08,   16 /* Private */,
      19,    0,  332,    2, 0x08,   17 /* Private */,
      20,    0,  333,    2, 0x08,   18 /* Private */,
      21,    0,  334,    2, 0x08,   19 /* Private */,
      22,    0,  335,    2, 0x08,   20 /* Private */,
      23,    3,  336,    2, 0x08,   21 /* Private */,
      27,    1,  343,    2, 0x08,   25 /* Private */,
      28,    0,  346,    2, 0x08,   27 /* Private */,
      29,    0,  347,    2, 0x08,   28 /* Private */,
      30,    4,  348,    2, 0x08,   29 /* Private */,
      35,    6,  357,    2, 0x08,   34 /* Private */,
      40,    6,  370,    2, 0x08,   41 /* Private */,
      41,    5,  383,    2, 0x08,   48 /* Private */,
      42,    5,  394,    2, 0x08,   54 /* Private */,
      43,    4,  405,    2, 0x08,   60 /* Private */,
      46,    5,  414,    2, 0x08,   65 /* Private */,
      47,    0,  425,    2, 0x08,   71 /* Private */,
      48,    4,  426,    2, 0x08,   72 /* Private */,
      49,    2,  435,    2, 0x08,   77 /* Private */,
      52,    3,  440,    2, 0x08,   80 /* Private */,
      53,    0,  447,    2, 0x08,   84 /* Private */,
      54,    4,  448,    2, 0x08,   85 /* Private */,
      55,    8,  457,    2, 0x08,   90 /* Private */,
      60,    8,  474,    2, 0x08,   99 /* Private */,
      61,    0,  491,    2, 0x08,  108 /* Private */,
      62,    0,  492,    2, 0x08,  109 /* Private */,
      63,    0,  493,    2, 0x08,  110 /* Private */,
      64,    0,  494,    2, 0x08,  111 /* Private */,
      65,    0,  495,    2, 0x08,  112 /* Private */,
      66,    0,  496,    2, 0x08,  113 /* Private */,
      67,    0,  497,    2, 0x08,  114 /* Private */,
      68,    0,  498,    2, 0x08,  115 /* Private */,
      69,    0,  499,    2, 0x08,  116 /* Private */,
      70,    0,  500,    2, 0x08,  117 /* Private */,
      71,    0,  501,    2, 0x08,  118 /* Private */,
      72,    0,  502,    2, 0x08,  119 /* Private */,
      73,    0,  503,    2, 0x08,  120 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   24,   25,   26,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   31,   32,   33,   34,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 38, QMetaType::Int, QMetaType::Int, QMetaType::Int,   36,   37,   39,   24,   25,   26,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 38, QMetaType::Int, QMetaType::Int, QMetaType::Int,   36,   37,   39,   24,   25,   26,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   36,   37,   24,   25,   26,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   36,   37,   24,   25,   26,
    QMetaType::Void, 0x80000000 | 44, QMetaType::Int, QMetaType::Int, QMetaType::Int,   45,   24,   25,   26,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   31,   32,   33,   34,
    QMetaType::Int, QMetaType::Int, QMetaType::Int,   50,   51,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   24,   25,   26,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   31,   32,   33,   34,
    QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   31,   32,   33,   34,   56,   57,   58,   59,
    QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   31,   32,   33,   34,   56,   57,   58,   59,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'Mouse_Pressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showMousePosition'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPoint &, std::false_type>,
        // method 'on_show_axes_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_set_point1_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_set_point2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_shGrid_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_spinBox_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_DrawDDALine_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_DrawBresenhamLine_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_polarCircle_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_bresenhamMidpointCircle_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_midpointEllipse_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_polarEllipse_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_setVertex_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_clearVertex_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_floodFill_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_boundaryFill_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'drawDDALine'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'delay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'initEdgeTable'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_scanLineFill_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'storeEdgeInTable'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'boundary_fill_8point'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QRgb, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'boundary_fill_4point'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QRgb, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'flood_fill_4point'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'flood_fill_8point'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'poly_draw'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::vector<std::pair<int,int> >, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'point'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'draw_Window'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'cohenSutherlandClip'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'computeCode'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'drawLineByStoringPoints'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'suthHodgClip'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clip'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'y_intersect'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'x_intersect'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_translation_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_scaling_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_shearing_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_rotation_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_reflection_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_setCorner_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_setCorner_1_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_drawAndStore_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_lineClip_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_polygonClip_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_setControlPoint_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_clearControlPoint_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_drawBezierCurve_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Mouse_Pressed(); break;
        case 1: _t->showMousePosition((*reinterpret_cast< std::add_pointer_t<QPoint&>>(_a[1]))); break;
        case 2: _t->on_show_axes_clicked(); break;
        case 3: _t->on_set_point1_clicked(); break;
        case 4: _t->on_set_point2_clicked(); break;
        case 5: _t->on_pushButton_clicked(); break;
        case 6: _t->on_pushButton_shGrid_clicked(); break;
        case 7: _t->on_spinBox_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->on_DrawDDALine_clicked(); break;
        case 9: _t->on_DrawBresenhamLine_clicked(); break;
        case 10: _t->on_polarCircle_clicked(); break;
        case 11: _t->on_bresenhamMidpointCircle_clicked(); break;
        case 12: _t->on_midpointEllipse_clicked(); break;
        case 13: _t->on_polarEllipse_clicked(); break;
        case 14: _t->on_setVertex_clicked(); break;
        case 15: _t->on_clearVertex_clicked(); break;
        case 16: _t->on_floodFill_clicked(); break;
        case 17: _t->on_boundaryFill_clicked(); break;
        case 18: _t->drawDDALine((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 19: _t->delay((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 20: _t->initEdgeTable(); break;
        case 21: _t->on_scanLineFill_clicked(); break;
        case 22: _t->storeEdgeInTable((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 23: _t->boundary_fill_8point((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QRgb>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6]))); break;
        case 24: _t->boundary_fill_4point((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QRgb>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6]))); break;
        case 25: _t->flood_fill_4point((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5]))); break;
        case 26: _t->flood_fill_8point((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5]))); break;
        case 27: _t->poly_draw((*reinterpret_cast< std::add_pointer_t<std::vector<std::pair<int,int>>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 28: _t->point((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5]))); break;
        case 29: _t->draw_Window(); break;
        case 30: _t->cohenSutherlandClip((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 31: { int _r = _t->computeCode((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 32: _t->drawLineByStoringPoints((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 33: _t->suthHodgClip(); break;
        case 34: _t->clip((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 35: { int _r = _t->y_intersect((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[8])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 36: { int _r = _t->x_intersect((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[8])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 37: _t->on_translation_clicked(); break;
        case 38: _t->on_scaling_clicked(); break;
        case 39: _t->on_shearing_clicked(); break;
        case 40: _t->on_rotation_clicked(); break;
        case 41: _t->on_reflection_clicked(); break;
        case 42: _t->on_setCorner_2_clicked(); break;
        case 43: _t->on_setCorner_1_clicked(); break;
        case 44: _t->on_drawAndStore_clicked(); break;
        case 45: _t->on_lineClip_clicked(); break;
        case 46: _t->on_polygonClip_clicked(); break;
        case 47: _t->on_setControlPoint_clicked(); break;
        case 48: _t->on_clearControlPoint_clicked(); break;
        case 49: _t->on_drawBezierCurve_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 50)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 50;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 50)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 50;
    }
    return _id;
}
QT_WARNING_POP
