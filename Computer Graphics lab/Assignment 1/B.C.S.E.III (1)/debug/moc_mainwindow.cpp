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
    "arg1",
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
    "on_cir_cartesian_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[48];
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
    char stringdata10[5];
    char stringdata11[24];
    char stringdata12[24];
    char stringdata13[9];
    char stringdata14[2];
    char stringdata15[2];
    char stringdata16[2];
    char stringdata17[24];
    char stringdata18[26];
    char stringdata19[21];
    char stringdata20[24];
    char stringdata21[24];
    char stringdata22[21];
    char stringdata23[25];
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
        QT_MOC_LITERAL(146, 4),  // "arg1"
        QT_MOC_LITERAL(151, 23),  // "on_pushButton_3_clicked"
        QT_MOC_LITERAL(175, 23),  // "on_pushButton_6_clicked"
        QT_MOC_LITERAL(199, 8),  // "setColor"
        QT_MOC_LITERAL(208, 1),  // "x"
        QT_MOC_LITERAL(210, 1),  // "y"
        QT_MOC_LITERAL(212, 1),  // "c"
        QT_MOC_LITERAL(214, 23),  // "on_pushButton_7_clicked"
        QT_MOC_LITERAL(238, 25),  // "on_Bresenham_line_clicked"
        QT_MOC_LITERAL(264, 20),  // "on_cir_polar_clicked"
        QT_MOC_LITERAL(285, 23),  // "on_cir_midpoint_clicked"
        QT_MOC_LITERAL(309, 23),  // "on_pushButton_4_clicked"
        QT_MOC_LITERAL(333, 20),  // "on_ell_polar_clicked"
        QT_MOC_LITERAL(354, 24)   // "on_cir_cartesian_clicked"
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
    "arg1",
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
    "on_cir_cartesian_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  110,    2, 0x0a,    1 /* Public */,
       3,    1,  111,    2, 0x0a,    2 /* Public */,
       6,    0,  114,    2, 0x08,    4 /* Private */,
       7,    0,  115,    2, 0x08,    5 /* Private */,
       8,    0,  116,    2, 0x08,    6 /* Private */,
       9,    1,  117,    2, 0x08,    7 /* Private */,
      11,    0,  120,    2, 0x08,    9 /* Private */,
      12,    0,  121,    2, 0x08,   10 /* Private */,
      13,    3,  122,    2, 0x08,   11 /* Private */,
      17,    0,  129,    2, 0x08,   15 /* Private */,
      18,    0,  130,    2, 0x08,   16 /* Private */,
      19,    0,  131,    2, 0x08,   17 /* Private */,
      20,    0,  132,    2, 0x08,   18 /* Private */,
      21,    0,  133,    2, 0x08,   19 /* Private */,
      22,    0,  134,    2, 0x08,   20 /* Private */,
      23,    0,  135,    2, 0x08,   21 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   14,   15,   16,
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
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_spinBox_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
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
        case 5: _t->on_spinBox_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
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
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP