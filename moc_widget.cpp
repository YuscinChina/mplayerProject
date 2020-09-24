/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created: Wed Sep 23 11:14:06 2020
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "widget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Widget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,    8,    7,    7, 0x05,
      50,   45,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      68,    7,    7,    7, 0x0a,
      79,    7,    7,    7, 0x0a,
      91,    7,    7,    7, 0x0a,
     102,    7,    7,    7, 0x0a,
     115,    7,    7,    7, 0x0a,
     127,    7,    7,    7, 0x0a,
     140,    7,    7,    7, 0x0a,
     153,    7,    7,    7, 0x0a,
     164,    7,    7,    7, 0x0a,
     186,  180,    7,    7, 0x08,
     224,   45,    7,    7, 0x08,
     241,    8,    7,    7, 0x08,
     273,  267,    7,    7, 0x08,
     306,  267,    7,    7, 0x08,
     353,  348,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Widget[] = {
    "Widget\0\0time1,time2\0sendTimePos(char*,char*)\0"
    "time\0sendSlider(char*)\0nextSong()\0"
    "cutButton()\0setSound()\0beforeSong()\0"
    "lyricOpen()\0closeLyric()\0singlePlay()\0"
    "listPlay()\0setSlideValue()\0value\0"
    "on_horizontalSlider_valueChanged(int)\0"
    "SliderJDT(char*)\0setLabelTime(char*,char*)\0"
    "index\0on_listPlay_clicked(QModelIndex)\0"
    "on_comboBoxStyle_currentIndexChanged(int)\0"
    "item\0on_listPlay_itemClicked(QListWidgetItem*)\0"
};

const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget,
      qt_meta_data_Widget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Widget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Widget))
        return static_cast<void*>(const_cast< Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sendTimePos((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2]))); break;
        case 1: sendSlider((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 2: nextSong(); break;
        case 3: cutButton(); break;
        case 4: setSound(); break;
        case 5: beforeSong(); break;
        case 6: lyricOpen(); break;
        case 7: closeLyric(); break;
        case 8: singlePlay(); break;
        case 9: listPlay(); break;
        case 10: setSlideValue(); break;
        case 11: on_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: SliderJDT((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 13: setLabelTime((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2]))); break;
        case 14: on_listPlay_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 15: on_comboBoxStyle_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: on_listPlay_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void Widget::sendTimePos(char * _t1, char * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Widget::sendSlider(char * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
