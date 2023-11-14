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
    "on_pushButton_clicked",
    "on_pushButton_2_clicked",
    "on_spinBox_textChanged",
    "on_pushButton_3_clicked",
    "on_pushButton_6_clicked",
    "setColor",
    "x",
    "y",
    "c",
    "on_pushButton_7_clicked",
    "on_Bresenham_line_clicked",
    "on_cir_polar_clicked",
    "on_cir_midpoint_clicked",
    "on_pushButton_4_clicked",
    "on_ell_polar_clicked",
    "on_cir_cartesian_clicked",
    "on_draw_poly_clicked",
    "on_boundary_fill_clicked",
    "boundary_fill",
    "QRgb",
    "fill_color",
    "boundary_color",
    "on_flood_fill_clicked",
    "flood_fill",
    "old_color",
    "on_scanline_clicked",
    "myDelay",
    "on_draw_background_clicked",
    "draw_background",
    "grass",
    "road",
    "center_line",
    "car",
    "translation",
    "val",
    "building",
    "val1",
    "val2",
    "val3",
    "sky",
    "sky_birds",
    "addLake",
    "get_speedValue",
    "on_start_clicked",
    "on_stop_clicked",
    "on_speedUp_clicked",
    "on_speedDown_clicked",
    "setMusic",
    "checkMusic"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[112];
    char stringdata0[11];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[18];
    char stringdata4[8];
    char stringdata5[4];
    char stringdata6[21];
    char stringdata7[22];
    char stringdata8[24];
    char stringdata9[23];
    char stringdata10[24];
    char stringdata11[24];
    char stringdata12[9];
    char stringdata13[2];
    char stringdata14[2];
    char stringdata15[2];
    char stringdata16[24];
    char stringdata17[26];
    char stringdata18[21];
    char stringdata19[24];
    char stringdata20[24];
    char stringdata21[21];
    char stringdata22[25];
    char stringdata23[21];
    char stringdata24[25];
    char stringdata25[14];
    char stringdata26[5];
    char stringdata27[11];
    char stringdata28[15];
    char stringdata29[22];
    char stringdata30[11];
    char stringdata31[10];
    char stringdata32[20];
    char stringdata33[8];
    char stringdata34[27];
    char stringdata35[16];
    char stringdata36[6];
    char stringdata37[5];
    char stringdata38[12];
    char stringdata39[4];
    char stringdata40[12];
    char stringdata41[4];
    char stringdata42[9];
    char stringdata43[5];
    char stringdata44[5];
    char stringdata45[5];
    char stringdata46[4];
    char stringdata47[10];
    char stringdata48[8];
    char stringdata49[15];
    char stringdata50[17];
    char stringdata51[16];
    char stringdata52[19];
    char stringdata53[21];
    char stringdata54[9];
    char stringdata55[11];
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
        QT_MOC_LITERAL(77, 21),  // "on_pushButton_clicked"
        QT_MOC_LITERAL(99, 23),  // "on_pushButton_2_clicked"
        QT_MOC_LITERAL(123, 22),  // "on_spinBox_textChanged"
        QT_MOC_LITERAL(146, 23),  // "on_pushButton_3_clicked"
        QT_MOC_LITERAL(170, 23),  // "on_pushButton_6_clicked"
        QT_MOC_LITERAL(194, 8),  // "setColor"
        QT_MOC_LITERAL(203, 1),  // "x"
        QT_MOC_LITERAL(205, 1),  // "y"
        QT_MOC_LITERAL(207, 1),  // "c"
        QT_MOC_LITERAL(209, 23),  // "on_pushButton_7_clicked"
        QT_MOC_LITERAL(233, 25),  // "on_Bresenham_line_clicked"
        QT_MOC_LITERAL(259, 20),  // "on_cir_polar_clicked"
        QT_MOC_LITERAL(280, 23),  // "on_cir_midpoint_clicked"
        QT_MOC_LITERAL(304, 23),  // "on_pushButton_4_clicked"
        QT_MOC_LITERAL(328, 20),  // "on_ell_polar_clicked"
        QT_MOC_LITERAL(349, 24),  // "on_cir_cartesian_clicked"
        QT_MOC_LITERAL(374, 20),  // "on_draw_poly_clicked"
        QT_MOC_LITERAL(395, 24),  // "on_boundary_fill_clicked"
        QT_MOC_LITERAL(420, 13),  // "boundary_fill"
        QT_MOC_LITERAL(434, 4),  // "QRgb"
        QT_MOC_LITERAL(439, 10),  // "fill_color"
        QT_MOC_LITERAL(450, 14),  // "boundary_color"
        QT_MOC_LITERAL(465, 21),  // "on_flood_fill_clicked"
        QT_MOC_LITERAL(487, 10),  // "flood_fill"
        QT_MOC_LITERAL(498, 9),  // "old_color"
        QT_MOC_LITERAL(508, 19),  // "on_scanline_clicked"
        QT_MOC_LITERAL(528, 7),  // "myDelay"
        QT_MOC_LITERAL(536, 26),  // "on_draw_background_clicked"
        QT_MOC_LITERAL(563, 15),  // "draw_background"
        QT_MOC_LITERAL(579, 5),  // "grass"
        QT_MOC_LITERAL(585, 4),  // "road"
        QT_MOC_LITERAL(590, 11),  // "center_line"
        QT_MOC_LITERAL(602, 3),  // "car"
        QT_MOC_LITERAL(606, 11),  // "translation"
        QT_MOC_LITERAL(618, 3),  // "val"
        QT_MOC_LITERAL(622, 8),  // "building"
        QT_MOC_LITERAL(631, 4),  // "val1"
        QT_MOC_LITERAL(636, 4),  // "val2"
        QT_MOC_LITERAL(641, 4),  // "val3"
        QT_MOC_LITERAL(646, 3),  // "sky"
        QT_MOC_LITERAL(650, 9),  // "sky_birds"
        QT_MOC_LITERAL(660, 7),  // "addLake"
        QT_MOC_LITERAL(668, 14),  // "get_speedValue"
        QT_MOC_LITERAL(683, 16),  // "on_start_clicked"
        QT_MOC_LITERAL(700, 15),  // "on_stop_clicked"
        QT_MOC_LITERAL(716, 18),  // "on_speedUp_clicked"
        QT_MOC_LITERAL(735, 20),  // "on_speedDown_clicked"
        QT_MOC_LITERAL(756, 8),  // "setMusic"
        QT_MOC_LITERAL(765, 10)   // "checkMusic"
    },
    "MainWindow",
    "Mouse_Pressed",
    "",
    "showMousePosition",
    "QPoint&",
    "pos",
    "on_show_axes_clicked",
    "on_pushButton_clicked",
    "on_pushButton_2_clicked",
    "on_spinBox_textChanged",
    "on_pushButton_3_clicked",
    "on_pushButton_6_clicked",
    "setColor",
    "x",
    "y",
    "c",
    "on_pushButton_7_clicked",
    "on_Bresenham_line_clicked",
    "on_cir_polar_clicked",
    "on_cir_midpoint_clicked",
    "on_pushButton_4_clicked",
    "on_ell_polar_clicked",
    "on_cir_cartesian_clicked",
    "on_draw_poly_clicked",
    "on_boundary_fill_clicked",
    "boundary_fill",
    "QRgb",
    "fill_color",
    "boundary_color",
    "on_flood_fill_clicked",
    "flood_fill",
    "old_color",
    "on_scanline_clicked",
    "myDelay",
    "on_draw_background_clicked",
    "draw_background",
    "grass",
    "road",
    "center_line",
    "car",
    "translation",
    "val",
    "building",
    "val1",
    "val2",
    "val3",
    "sky",
    "sky_birds",
    "addLake",
    "get_speedValue",
    "on_start_clicked",
    "on_stop_clicked",
    "on_speedUp_clicked",
    "on_speedDown_clicked",
    "setMusic",
    "checkMusic"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      41,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  260,    2, 0x0a,    1 /* Public */,
       3,    1,  261,    2, 0x0a,    2 /* Public */,
       6,    0,  264,    2, 0x08,    4 /* Private */,
       7,    0,  265,    2, 0x08,    5 /* Private */,
       8,    0,  266,    2, 0x08,    6 /* Private */,
       9,    0,  267,    2, 0x08,    7 /* Private */,
      10,    0,  268,    2, 0x08,    8 /* Private */,
      11,    0,  269,    2, 0x08,    9 /* Private */,
      12,    3,  270,    2, 0x08,   10 /* Private */,
      16,    0,  277,    2, 0x08,   14 /* Private */,
      17,    0,  278,    2, 0x08,   15 /* Private */,
      18,    0,  279,    2, 0x08,   16 /* Private */,
      19,    0,  280,    2, 0x08,   17 /* Private */,
      20,    0,  281,    2, 0x08,   18 /* Private */,
      21,    0,  282,    2, 0x08,   19 /* Private */,
      22,    0,  283,    2, 0x08,   20 /* Private */,
      23,    0,  284,    2, 0x08,   21 /* Private */,
      24,    0,  285,    2, 0x08,   22 /* Private */,
      25,    4,  286,    2, 0x08,   23 /* Private */,
      29,    0,  295,    2, 0x08,   28 /* Private */,
      30,    3,  296,    2, 0x08,   29 /* Private */,
      32,    0,  303,    2, 0x08,   33 /* Private */,
      33,    0,  304,    2, 0x08,   34 /* Private */,
      34,    0,  305,    2, 0x08,   35 /* Private */,
      35,    0,  306,    2, 0x08,   36 /* Private */,
      36,    0,  307,    2, 0x08,   37 /* Private */,
      37,    0,  308,    2, 0x08,   38 /* Private */,
      38,    0,  309,    2, 0x08,   39 /* Private */,
      39,    0,  310,    2, 0x08,   40 /* Private */,
      40,    1,  311,    2, 0x08,   41 /* Private */,
      42,    3,  314,    2, 0x08,   43 /* Private */,
      46,    0,  321,    2, 0x08,   47 /* Private */,
      47,    0,  322,    2, 0x08,   48 /* Private */,
      48,    0,  323,    2, 0x08,   49 /* Private */,
      49,    0,  324,    2, 0x08,   50 /* Private */,
      50,    0,  325,    2, 0x08,   51 /* Private */,
      51,    0,  326,    2, 0x08,   52 /* Private */,
      52,    0,  327,    2, 0x08,   53 /* Private */,
      53,    0,  328,    2, 0x08,   54 /* Private */,
      54,    0,  329,    2, 0x08,   55 /* Private */,
      55,    0,  330,    2, 0x08,   56 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   13,   14,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 26, 0x80000000 | 26,   13,   14,   27,   28,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 26,   13,   14,   31,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   41,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   43,   44,   45,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int,
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
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_spinBox_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_3_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_6_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setColor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_pushButton_7_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Bresenham_line_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_cir_polar_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_cir_midpoint_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_4_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ell_polar_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_cir_cartesian_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_draw_poly_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_boundary_fill_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'boundary_fill'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QRgb, std::false_type>,
        QtPrivate::TypeAndForceComplete<QRgb, std::false_type>,
        // method 'on_flood_fill_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'flood_fill'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QRgb, std::false_type>,
        // method 'on_scanline_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'myDelay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_draw_background_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'draw_background'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'grass'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'road'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'center_line'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'car'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'translation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'building'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'sky'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sky_birds'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addLake'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'get_speedValue'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_start_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_stop_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_speedUp_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_speedDown_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setMusic'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'checkMusic'
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
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->on_pushButton_2_clicked(); break;
        case 5: _t->on_spinBox_textChanged(); break;
        case 6: _t->on_pushButton_3_clicked(); break;
        case 7: _t->on_pushButton_6_clicked(); break;
        case 8: _t->setColor((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 9: _t->on_pushButton_7_clicked(); break;
        case 10: _t->on_Bresenham_line_clicked(); break;
        case 11: _t->on_cir_polar_clicked(); break;
        case 12: _t->on_cir_midpoint_clicked(); break;
        case 13: _t->on_pushButton_4_clicked(); break;
        case 14: _t->on_ell_polar_clicked(); break;
        case 15: _t->on_cir_cartesian_clicked(); break;
        case 16: _t->on_draw_poly_clicked(); break;
        case 17: _t->on_boundary_fill_clicked(); break;
        case 18: _t->boundary_fill((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QRgb>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QRgb>>(_a[4]))); break;
        case 19: _t->on_flood_fill_clicked(); break;
        case 20: _t->flood_fill((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QRgb>>(_a[3]))); break;
        case 21: _t->on_scanline_clicked(); break;
        case 22: _t->myDelay(); break;
        case 23: _t->on_draw_background_clicked(); break;
        case 24: _t->draw_background(); break;
        case 25: _t->grass(); break;
        case 26: _t->road(); break;
        case 27: _t->center_line(); break;
        case 28: _t->car(); break;
        case 29: _t->translation((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 30: _t->building((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 31: _t->sky(); break;
        case 32: _t->sky_birds(); break;
        case 33: _t->addLake(); break;
        case 34: { int _r = _t->get_speedValue();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 35: _t->on_start_clicked(); break;
        case 36: _t->on_stop_clicked(); break;
        case 37: _t->on_speedUp_clicked(); break;
        case 38: _t->on_speedDown_clicked(); break;
        case 39: _t->setMusic(); break;
        case 40: _t->checkMusic(); break;
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
        if (_id < 41)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 41;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 41)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 41;
    }
    return _id;
}
QT_WARNING_POP
