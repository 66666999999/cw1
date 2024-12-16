/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[28];
    char stringdata0[378];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "sig_reversePlay"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 19), // "sig_reverseProgress"
QT_MOC_LITERAL(4, 48, 14), // "connect2Player"
QT_MOC_LITERAL(5, 63, 19), // "highlightInFileList"
QT_MOC_LITERAL(6, 83, 16), // "showNormalWidget"
QT_MOC_LITERAL(7, 100, 17), // "showReverseWidget"
QT_MOC_LITERAL(8, 118, 15), // "changePlayOrder"
QT_MOC_LITERAL(9, 134, 13), // "initSeekFrame"
QT_MOC_LITERAL(10, 148, 15), // "deleteSeekFrame"
QT_MOC_LITERAL(11, 164, 4), // "seek"
QT_MOC_LITERAL(12, 169, 12), // "changeVolume"
QT_MOC_LITERAL(13, 182, 10), // "changeMute"
QT_MOC_LITERAL(14, 193, 5), // "pause"
QT_MOC_LITERAL(15, 199, 4), // "play"
QT_MOC_LITERAL(16, 204, 11), // "playClicked"
QT_MOC_LITERAL(17, 216, 21), // "skipForwardOrBackward"
QT_MOC_LITERAL(18, 238, 4), // "jump"
QT_MOC_LITERAL(19, 243, 14), // "positionChange"
QT_MOC_LITERAL(20, 258, 8), // "progress"
QT_MOC_LITERAL(21, 267, 16), // "reverseShowRatio"
QT_MOC_LITERAL(22, 284, 21), // "openFileButtonClicked"
QT_MOC_LITERAL(23, 306, 12), // "addVideoItem"
QT_MOC_LITERAL(24, 319, 11), // "changeVideo"
QT_MOC_LITERAL(25, 331, 17), // "onDurationChanged"
QT_MOC_LITERAL(26, 349, 8), // "duration"
QT_MOC_LITERAL(27, 358, 19) // "on_speedBtn_clicked"

    },
    "MainWindow\0sig_reversePlay\0\0"
    "sig_reverseProgress\0connect2Player\0"
    "highlightInFileList\0showNormalWidget\0"
    "showReverseWidget\0changePlayOrder\0"
    "initSeekFrame\0deleteSeekFrame\0seek\0"
    "changeVolume\0changeMute\0pause\0play\0"
    "playClicked\0skipForwardOrBackward\0"
    "jump\0positionChange\0progress\0"
    "reverseShowRatio\0openFileButtonClicked\0"
    "addVideoItem\0changeVideo\0onDurationChanged\0"
    "duration\0on_speedBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  134,    2, 0x06 /* Public */,
       3,    1,  137,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,  140,    2, 0x0a /* Public */,
       5,    0,  141,    2, 0x0a /* Public */,
       6,    0,  142,    2, 0x0a /* Public */,
       7,    0,  143,    2, 0x0a /* Public */,
       8,    0,  144,    2, 0x0a /* Public */,
       9,    1,  145,    2, 0x0a /* Public */,
      10,    0,  148,    2, 0x0a /* Public */,
      11,    1,  149,    2, 0x0a /* Public */,
      12,    1,  152,    2, 0x0a /* Public */,
      13,    0,  155,    2, 0x0a /* Public */,
      14,    0,  156,    2, 0x0a /* Public */,
      15,    0,  157,    2, 0x0a /* Public */,
      16,    0,  158,    2, 0x0a /* Public */,
      17,    1,  159,    2, 0x0a /* Public */,
      18,    1,  162,    2, 0x0a /* Public */,
      19,    1,  165,    2, 0x0a /* Public */,
      21,    1,  168,    2, 0x0a /* Public */,
      22,    0,  171,    2, 0x0a /* Public */,
      23,    1,  172,    2, 0x0a /* Public */,
      24,    1,  175,    2, 0x0a /* Public */,
      25,    1,  178,    2, 0x0a /* Public */,
      27,    0,  181,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::LongLong,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::LongLong,   20,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::LongLong,   26,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_reversePlay((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sig_reverseProgress((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 2: _t->connect2Player(); break;
        case 3: _t->highlightInFileList(); break;
        case 4: _t->showNormalWidget(); break;
        case 5: _t->showReverseWidget(); break;
        case 6: _t->changePlayOrder(); break;
        case 7: _t->initSeekFrame((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->deleteSeekFrame(); break;
        case 9: _t->seek((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 10: _t->changeVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->changeMute(); break;
        case 12: _t->pause(); break;
        case 13: _t->play(); break;
        case 14: _t->playClicked(); break;
        case 15: _t->skipForwardOrBackward((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->jump((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->positionChange((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 18: _t->reverseShowRatio((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 19: _t->openFileButtonClicked(); break;
        case 20: _t->addVideoItem((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 21: _t->changeVideo((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: _t->onDurationChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 23: _t->on_speedBtn_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sig_reversePlay)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sig_reverseProgress)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 24)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 24;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::sig_reversePlay(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::sig_reverseProgress(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
