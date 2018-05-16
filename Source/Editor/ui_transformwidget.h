/********************************************************************************
** Form generated from reading UI file 'transformwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFORMWIDGET_H
#define UI_TRANSFORMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TransformWidget
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_31;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_32;
    QDoubleSpinBox *spin_PosY_9;
    QLabel *label_33;
    QDoubleSpinBox *spin_PosX_9;
    QLabel *label_34;
    QDoubleSpinBox *spin_PosZ_9;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_27;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_28;
    QDoubleSpinBox *spin_PosY_8;
    QLabel *label_29;
    QDoubleSpinBox *spin_PosX_8;
    QLabel *label_30;
    QDoubleSpinBox *spin_PosZ_8;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_14;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_11;
    QDoubleSpinBox *spin_PosY_4;
    QLabel *label_12;
    QDoubleSpinBox *spin_PosX_4;
    QLabel *label_13;
    QDoubleSpinBox *spin_PosZ_4;
    QLabel *label;

    void setupUi(QWidget *TransformWidget)
    {
        if (TransformWidget->objectName().isEmpty())
            TransformWidget->setObjectName(QStringLiteral("TransformWidget"));
        TransformWidget->resize(300, 256);
        TransformWidget->setMaximumSize(QSize(16777215, 256));
        TransformWidget->setStyleSheet(QStringLiteral(""));
        gridLayout_3 = new QGridLayout(TransformWidget);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(6);
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_31 = new QLabel(TransformWidget);
        label_31->setObjectName(QStringLiteral("label_31"));

        horizontalLayout_14->addWidget(label_31);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_32 = new QLabel(TransformWidget);
        label_32->setObjectName(QStringLiteral("label_32"));
        QPalette palette;
        QBrush brush(QColor(234, 76, 76, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(49, 54, 59, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(61, 174, 233, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        QBrush brush3(QColor(239, 240, 241, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        label_32->setPalette(palette);
        label_32->setStyleSheet(QStringLiteral("color: #EA4C4C;"));
        label_32->setAlignment(Qt::AlignCenter);

        horizontalLayout_15->addWidget(label_32);

        spin_PosY_9 = new QDoubleSpinBox(TransformWidget);
        spin_PosY_9->setObjectName(QStringLiteral("spin_PosY_9"));

        horizontalLayout_15->addWidget(spin_PosY_9);

        label_33 = new QLabel(TransformWidget);
        label_33->setObjectName(QStringLiteral("label_33"));
        QPalette palette1;
        QBrush brush4(QColor(162, 239, 68, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette1.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        label_33->setPalette(palette1);
        label_33->setStyleSheet(QStringLiteral("color: #A2EF44;"));
        label_33->setAlignment(Qt::AlignCenter);

        horizontalLayout_15->addWidget(label_33);

        spin_PosX_9 = new QDoubleSpinBox(TransformWidget);
        spin_PosX_9->setObjectName(QStringLiteral("spin_PosX_9"));

        horizontalLayout_15->addWidget(spin_PosX_9);

        label_34 = new QLabel(TransformWidget);
        label_34->setObjectName(QStringLiteral("label_34"));
        QPalette palette2;
        QBrush brush5(QColor(36, 189, 223, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush5);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette2.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        label_34->setPalette(palette2);
        label_34->setStyleSheet(QStringLiteral("color: #24BDDF"));
        label_34->setAlignment(Qt::AlignCenter);

        horizontalLayout_15->addWidget(label_34);

        spin_PosZ_9 = new QDoubleSpinBox(TransformWidget);
        spin_PosZ_9->setObjectName(QStringLiteral("spin_PosZ_9"));

        horizontalLayout_15->addWidget(spin_PosZ_9);


        horizontalLayout_14->addLayout(horizontalLayout_15);


        gridLayout_2->addLayout(horizontalLayout_14, 2, 0, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_27 = new QLabel(TransformWidget);
        label_27->setObjectName(QStringLiteral("label_27"));

        horizontalLayout_12->addWidget(label_27);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_28 = new QLabel(TransformWidget);
        label_28->setObjectName(QStringLiteral("label_28"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette3.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        label_28->setPalette(palette3);
        label_28->setStyleSheet(QStringLiteral("color: #EA4C4C;"));
        label_28->setAlignment(Qt::AlignCenter);

        horizontalLayout_13->addWidget(label_28);

        spin_PosY_8 = new QDoubleSpinBox(TransformWidget);
        spin_PosY_8->setObjectName(QStringLiteral("spin_PosY_8"));

        horizontalLayout_13->addWidget(spin_PosY_8);

        label_29 = new QLabel(TransformWidget);
        label_29->setObjectName(QStringLiteral("label_29"));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette4.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        label_29->setPalette(palette4);
        label_29->setStyleSheet(QStringLiteral("color: #A2EF44;"));
        label_29->setAlignment(Qt::AlignCenter);

        horizontalLayout_13->addWidget(label_29);

        spin_PosX_8 = new QDoubleSpinBox(TransformWidget);
        spin_PosX_8->setObjectName(QStringLiteral("spin_PosX_8"));

        horizontalLayout_13->addWidget(spin_PosX_8);

        label_30 = new QLabel(TransformWidget);
        label_30->setObjectName(QStringLiteral("label_30"));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush5);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette5.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush5);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush5);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        label_30->setPalette(palette5);
        label_30->setStyleSheet(QStringLiteral("color: #24BDDF"));
        label_30->setAlignment(Qt::AlignCenter);

        horizontalLayout_13->addWidget(label_30);

        spin_PosZ_8 = new QDoubleSpinBox(TransformWidget);
        spin_PosZ_8->setObjectName(QStringLiteral("spin_PosZ_8"));

        horizontalLayout_13->addWidget(spin_PosZ_8);


        horizontalLayout_12->addLayout(horizontalLayout_13);


        gridLayout_2->addLayout(horizontalLayout_12, 3, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_14 = new QLabel(TransformWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_14);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_11 = new QLabel(TransformWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette6.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        label_11->setPalette(palette6);
        label_11->setStyleSheet(QStringLiteral("color: #EA4C4C;"));
        label_11->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_11);

        spin_PosY_4 = new QDoubleSpinBox(TransformWidget);
        spin_PosY_4->setObjectName(QStringLiteral("spin_PosY_4"));

        horizontalLayout_4->addWidget(spin_PosY_4);

        label_12 = new QLabel(TransformWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette7.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        label_12->setPalette(palette7);
        label_12->setStyleSheet(QStringLiteral("color: #A2EF44;"));
        label_12->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_12);

        spin_PosX_4 = new QDoubleSpinBox(TransformWidget);
        spin_PosX_4->setObjectName(QStringLiteral("spin_PosX_4"));

        horizontalLayout_4->addWidget(spin_PosX_4);

        label_13 = new QLabel(TransformWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush5);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette8.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush5);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush5);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush5);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        label_13->setPalette(palette8);
        label_13->setStyleSheet(QStringLiteral("color: #24BDDF"));
        label_13->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_13);

        spin_PosZ_4 = new QDoubleSpinBox(TransformWidget);
        spin_PosZ_4->setObjectName(QStringLiteral("spin_PosZ_4"));

        horizontalLayout_4->addWidget(spin_PosZ_4);


        horizontalLayout_5->addLayout(horizontalLayout_4);


        gridLayout_2->addLayout(horizontalLayout_5, 1, 0, 1, 1);

        label = new QLabel(TransformWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 16));
        label->setStyleSheet(QStringLiteral("background:rgb(32, 32, 32)"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 2, 0, 1, 1);


        retranslateUi(TransformWidget);

        QMetaObject::connectSlotsByName(TransformWidget);
    } // setupUi

    void retranslateUi(QWidget *TransformWidget)
    {
        TransformWidget->setWindowTitle(QApplication::translate("TransformWidget", "Form", nullptr));
        label_31->setText(QApplication::translate("TransformWidget", "Rotation:", nullptr));
        label_32->setText(QApplication::translate("TransformWidget", "X", nullptr));
        label_33->setText(QApplication::translate("TransformWidget", "Y", nullptr));
        label_34->setText(QApplication::translate("TransformWidget", "Z", nullptr));
        label_27->setText(QApplication::translate("TransformWidget", "Scale:", nullptr));
        label_28->setText(QApplication::translate("TransformWidget", "X", nullptr));
        label_29->setText(QApplication::translate("TransformWidget", "Y", nullptr));
        label_30->setText(QApplication::translate("TransformWidget", "Z", nullptr));
        label_14->setText(QApplication::translate("TransformWidget", "Position:", nullptr));
        label_11->setText(QApplication::translate("TransformWidget", "X", nullptr));
        label_12->setText(QApplication::translate("TransformWidget", "Y", nullptr));
        label_13->setText(QApplication::translate("TransformWidget", "Z", nullptr));
        label->setText(QApplication::translate("TransformWidget", "Transform Component", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TransformWidget: public Ui_TransformWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFORMWIDGET_H
