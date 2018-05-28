/********************************************************************************
** Form generated from reading UI file 'BoxColliderWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOXCOLLIDERWIDGET_H
#define UI_BOXCOLLIDERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BoxColliderWidget
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_21;
    QLabel *label_32;
    QLabel *label_33;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_22;
    QDoubleSpinBox *spin_PosY_7;
    QLabel *label_23;
    QDoubleSpinBox *spin_PosX_7;
    QLabel *label_24;
    QDoubleSpinBox *spin_PosZ_7;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_25;
    QDoubleSpinBox *spin_PosY_8;
    QLabel *label_26;
    QDoubleSpinBox *spin_PosX_8;
    QLabel *label_34;
    QDoubleSpinBox *spin_PosZ_8;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_35;
    QDoubleSpinBox *spin_PosY_9;
    QLabel *label_36;
    QDoubleSpinBox *spin_PosX_9;
    QLabel *label_37;
    QDoubleSpinBox *spin_PosZ_9;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_2;
    QDoubleSpinBox *doubleSpinBox_3;

    void setupUi(QWidget *BoxColliderWidget)
    {
        if (BoxColliderWidget->objectName().isEmpty())
            BoxColliderWidget->setObjectName(QStringLiteral("BoxColliderWidget"));
        BoxColliderWidget->resize(335, 203);
        gridLayout = new QGridLayout(BoxColliderWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 6, 0, 6);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_21 = new QLabel(BoxColliderWidget);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(label_21);

        label_32 = new QLabel(BoxColliderWidget);
        label_32->setObjectName(QStringLiteral("label_32"));

        verticalLayout->addWidget(label_32);

        label_33 = new QLabel(BoxColliderWidget);
        label_33->setObjectName(QStringLiteral("label_33"));

        verticalLayout->addWidget(label_33);

        label_28 = new QLabel(BoxColliderWidget);
        label_28->setObjectName(QStringLiteral("label_28"));

        verticalLayout->addWidget(label_28);

        label_29 = new QLabel(BoxColliderWidget);
        label_29->setObjectName(QStringLiteral("label_29"));

        verticalLayout->addWidget(label_29);

        label_30 = new QLabel(BoxColliderWidget);
        label_30->setObjectName(QStringLiteral("label_30"));

        verticalLayout->addWidget(label_30);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_22 = new QLabel(BoxColliderWidget);
        label_22->setObjectName(QStringLiteral("label_22"));
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
        label_22->setPalette(palette);
        label_22->setStyleSheet(QStringLiteral("color: #EA4C4C;"));
        label_22->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_22);

        spin_PosY_7 = new QDoubleSpinBox(BoxColliderWidget);
        spin_PosY_7->setObjectName(QStringLiteral("spin_PosY_7"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(spin_PosY_7->sizePolicy().hasHeightForWidth());
        spin_PosY_7->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(spin_PosY_7);

        label_23 = new QLabel(BoxColliderWidget);
        label_23->setObjectName(QStringLiteral("label_23"));
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
        label_23->setPalette(palette1);
        label_23->setStyleSheet(QStringLiteral("color: #A2EF44;"));
        label_23->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_23);

        spin_PosX_7 = new QDoubleSpinBox(BoxColliderWidget);
        spin_PosX_7->setObjectName(QStringLiteral("spin_PosX_7"));
        sizePolicy.setHeightForWidth(spin_PosX_7->sizePolicy().hasHeightForWidth());
        spin_PosX_7->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(spin_PosX_7);

        label_24 = new QLabel(BoxColliderWidget);
        label_24->setObjectName(QStringLiteral("label_24"));
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
        label_24->setPalette(palette2);
        label_24->setStyleSheet(QStringLiteral("color: #24BDDF"));
        label_24->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_24);

        spin_PosZ_7 = new QDoubleSpinBox(BoxColliderWidget);
        spin_PosZ_7->setObjectName(QStringLiteral("spin_PosZ_7"));
        sizePolicy.setHeightForWidth(spin_PosZ_7->sizePolicy().hasHeightForWidth());
        spin_PosZ_7->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(spin_PosZ_7);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_25 = new QLabel(BoxColliderWidget);
        label_25->setObjectName(QStringLiteral("label_25"));
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
        label_25->setPalette(palette3);
        label_25->setStyleSheet(QStringLiteral("color: #EA4C4C;"));
        label_25->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_25);

        spin_PosY_8 = new QDoubleSpinBox(BoxColliderWidget);
        spin_PosY_8->setObjectName(QStringLiteral("spin_PosY_8"));
        sizePolicy.setHeightForWidth(spin_PosY_8->sizePolicy().hasHeightForWidth());
        spin_PosY_8->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(spin_PosY_8);

        label_26 = new QLabel(BoxColliderWidget);
        label_26->setObjectName(QStringLiteral("label_26"));
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
        label_26->setPalette(palette4);
        label_26->setStyleSheet(QStringLiteral("color: #A2EF44;"));
        label_26->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_26);

        spin_PosX_8 = new QDoubleSpinBox(BoxColliderWidget);
        spin_PosX_8->setObjectName(QStringLiteral("spin_PosX_8"));
        sizePolicy.setHeightForWidth(spin_PosX_8->sizePolicy().hasHeightForWidth());
        spin_PosX_8->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(spin_PosX_8);

        label_34 = new QLabel(BoxColliderWidget);
        label_34->setObjectName(QStringLiteral("label_34"));
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
        label_34->setPalette(palette5);
        label_34->setStyleSheet(QStringLiteral("color: #24BDDF"));
        label_34->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_34);

        spin_PosZ_8 = new QDoubleSpinBox(BoxColliderWidget);
        spin_PosZ_8->setObjectName(QStringLiteral("spin_PosZ_8"));
        sizePolicy.setHeightForWidth(spin_PosZ_8->sizePolicy().hasHeightForWidth());
        spin_PosZ_8->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(spin_PosZ_8);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_35 = new QLabel(BoxColliderWidget);
        label_35->setObjectName(QStringLiteral("label_35"));
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
        label_35->setPalette(palette6);
        label_35->setStyleSheet(QStringLiteral("color: #EA4C4C;"));
        label_35->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_35);

        spin_PosY_9 = new QDoubleSpinBox(BoxColliderWidget);
        spin_PosY_9->setObjectName(QStringLiteral("spin_PosY_9"));
        sizePolicy.setHeightForWidth(spin_PosY_9->sizePolicy().hasHeightForWidth());
        spin_PosY_9->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(spin_PosY_9);

        label_36 = new QLabel(BoxColliderWidget);
        label_36->setObjectName(QStringLiteral("label_36"));
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
        label_36->setPalette(palette7);
        label_36->setStyleSheet(QStringLiteral("color: #A2EF44;"));
        label_36->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_36);

        spin_PosX_9 = new QDoubleSpinBox(BoxColliderWidget);
        spin_PosX_9->setObjectName(QStringLiteral("spin_PosX_9"));
        sizePolicy.setHeightForWidth(spin_PosX_9->sizePolicy().hasHeightForWidth());
        spin_PosX_9->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(spin_PosX_9);

        label_37 = new QLabel(BoxColliderWidget);
        label_37->setObjectName(QStringLiteral("label_37"));
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
        label_37->setPalette(palette8);
        label_37->setStyleSheet(QStringLiteral("color: #24BDDF"));
        label_37->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_37);

        spin_PosZ_9 = new QDoubleSpinBox(BoxColliderWidget);
        spin_PosZ_9->setObjectName(QStringLiteral("spin_PosZ_9"));
        sizePolicy.setHeightForWidth(spin_PosZ_9->sizePolicy().hasHeightForWidth());
        spin_PosZ_9->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(spin_PosZ_9);


        verticalLayout_4->addLayout(horizontalLayout_8);

        doubleSpinBox = new QDoubleSpinBox(BoxColliderWidget);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));

        verticalLayout_4->addWidget(doubleSpinBox);

        doubleSpinBox_2 = new QDoubleSpinBox(BoxColliderWidget);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));

        verticalLayout_4->addWidget(doubleSpinBox_2);

        doubleSpinBox_3 = new QDoubleSpinBox(BoxColliderWidget);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));

        verticalLayout_4->addWidget(doubleSpinBox_3);


        horizontalLayout->addLayout(verticalLayout_4);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(BoxColliderWidget);

        QMetaObject::connectSlotsByName(BoxColliderWidget);
    } // setupUi

    void retranslateUi(QWidget *BoxColliderWidget)
    {
        BoxColliderWidget->setWindowTitle(QApplication::translate("BoxColliderWidget", "Form", nullptr));
        label_21->setText(QApplication::translate("BoxColliderWidget", "Position:", nullptr));
        label_32->setText(QApplication::translate("BoxColliderWidget", "Rotation:", nullptr));
        label_33->setText(QApplication::translate("BoxColliderWidget", "Dimensions:", nullptr));
        label_28->setText(QApplication::translate("BoxColliderWidget", "Static Friction:", nullptr));
        label_29->setText(QApplication::translate("BoxColliderWidget", "Dynamic Friction:", nullptr));
        label_30->setText(QApplication::translate("BoxColliderWidget", "Restitution:", nullptr));
        label_22->setText(QApplication::translate("BoxColliderWidget", "X", nullptr));
        label_23->setText(QApplication::translate("BoxColliderWidget", "Y", nullptr));
        label_24->setText(QApplication::translate("BoxColliderWidget", "Z", nullptr));
        label_25->setText(QApplication::translate("BoxColliderWidget", "X", nullptr));
        label_26->setText(QApplication::translate("BoxColliderWidget", "Y", nullptr));
        label_34->setText(QApplication::translate("BoxColliderWidget", "Z", nullptr));
        label_35->setText(QApplication::translate("BoxColliderWidget", "X", nullptr));
        label_36->setText(QApplication::translate("BoxColliderWidget", "Y", nullptr));
        label_37->setText(QApplication::translate("BoxColliderWidget", "Z", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BoxColliderWidget: public Ui_BoxColliderWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOXCOLLIDERWIDGET_H
