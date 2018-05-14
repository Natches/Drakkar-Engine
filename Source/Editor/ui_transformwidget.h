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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TransformWidget
{
public:
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *spin_PosX;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDoubleSpinBox *spin_PosY;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDoubleSpinBox *spin_PosZ;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QDoubleSpinBox *spin_RotX;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QDoubleSpinBox *spin_RotY;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QDoubleSpinBox *spin_RotZ;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QDoubleSpinBox *spin_ScaleX;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QDoubleSpinBox *spin_ScaleY;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QDoubleSpinBox *spin_ScaleZ;
    QLabel *label_10;

    void setupUi(QWidget *TransformWidget)
    {
        if (TransformWidget->objectName().isEmpty())
            TransformWidget->setObjectName(QStringLiteral("TransformWidget"));
        TransformWidget->resize(220, 486);
        TransformWidget->setMaximumSize(QSize(16777215, 486));
        TransformWidget->setStyleSheet(QStringLiteral(""));
        gridLayout_4 = new QGridLayout(TransformWidget);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBox = new QGroupBox(TransformWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(200, 144));
        groupBox->setMaximumSize(QSize(16777215, 16777215));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
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
        label->setPalette(palette);
        label->setStyleSheet(QStringLiteral("color: #EA4C4C;"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        spin_PosX = new QDoubleSpinBox(groupBox);
        spin_PosX->setObjectName(QStringLiteral("spin_PosX"));

        horizontalLayout->addWidget(spin_PosX);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
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
        label_2->setPalette(palette1);
        label_2->setStyleSheet(QStringLiteral("color: #A2EF44;"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        spin_PosY = new QDoubleSpinBox(groupBox);
        spin_PosY->setObjectName(QStringLiteral("spin_PosY"));

        horizontalLayout_2->addWidget(spin_PosY);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
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
        label_3->setPalette(palette2);
        label_3->setStyleSheet(QStringLiteral("color: #24BDDF"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_3);

        spin_PosZ = new QDoubleSpinBox(groupBox);
        spin_PosZ->setObjectName(QStringLiteral("spin_PosZ"));

        horizontalLayout_3->addWidget(spin_PosZ);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        verticalLayout_4->addWidget(groupBox);

        groupBox_2 = new QGroupBox(TransformWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(200, 144));
        groupBox_2->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
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
        label_4->setPalette(palette3);
        label_4->setStyleSheet(QStringLiteral("color: #EA4C4C;"));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_4);

        spin_RotX = new QDoubleSpinBox(groupBox_2);
        spin_RotX->setObjectName(QStringLiteral("spin_RotX"));

        horizontalLayout_4->addWidget(spin_RotX);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
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
        label_5->setPalette(palette4);
        label_5->setStyleSheet(QStringLiteral("color: #A2EF44;"));
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_5);

        spin_RotY = new QDoubleSpinBox(groupBox_2);
        spin_RotY->setObjectName(QStringLiteral("spin_RotY"));

        horizontalLayout_5->addWidget(spin_RotY);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
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
        label_6->setPalette(palette5);
        label_6->setStyleSheet(QStringLiteral("color: #24BDDF"));
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_6);

        spin_RotZ = new QDoubleSpinBox(groupBox_2);
        spin_RotZ->setObjectName(QStringLiteral("spin_RotZ"));

        horizontalLayout_6->addWidget(spin_RotZ);


        verticalLayout_2->addLayout(horizontalLayout_6);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);


        verticalLayout_4->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(TransformWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(200, 144));
        groupBox_3->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));
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
        label_7->setPalette(palette6);
        label_7->setStyleSheet(QStringLiteral("color: #EA4C4C;"));
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_7);

        spin_ScaleX = new QDoubleSpinBox(groupBox_3);
        spin_ScaleX->setObjectName(QStringLiteral("spin_ScaleX"));

        horizontalLayout_7->addWidget(spin_ScaleX);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));
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
        label_8->setPalette(palette7);
        label_8->setStyleSheet(QStringLiteral("color: #A2EF44;"));
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_8);

        spin_ScaleY = new QDoubleSpinBox(groupBox_3);
        spin_ScaleY->setObjectName(QStringLiteral("spin_ScaleY"));

        horizontalLayout_8->addWidget(spin_ScaleY);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QStringLiteral("label_9"));
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
        label_9->setPalette(palette8);
        label_9->setStyleSheet(QStringLiteral("color: #24BDDF"));
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_9);

        spin_ScaleZ = new QDoubleSpinBox(groupBox_3);
        spin_ScaleZ->setObjectName(QStringLiteral("spin_ScaleZ"));

        horizontalLayout_9->addWidget(spin_ScaleZ);


        verticalLayout_3->addLayout(horizontalLayout_9);


        gridLayout_3->addLayout(verticalLayout_3, 0, 0, 1, 1);


        verticalLayout_4->addWidget(groupBox_3);


        gridLayout_4->addLayout(verticalLayout_4, 1, 0, 1, 1);

        label_10 = new QLabel(TransformWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(0, 16));
        label_10->setMaximumSize(QSize(16777215, 16));
        label_10->setStyleSheet(QStringLiteral("background: #232629"));

        gridLayout_4->addWidget(label_10, 0, 0, 1, 1);


        retranslateUi(TransformWidget);

        QMetaObject::connectSlotsByName(TransformWidget);
    } // setupUi

    void retranslateUi(QWidget *TransformWidget)
    {
        TransformWidget->setWindowTitle(QApplication::translate("TransformWidget", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("TransformWidget", "Position", nullptr));
        label->setText(QApplication::translate("TransformWidget", "X", nullptr));
        label_2->setText(QApplication::translate("TransformWidget", "Y", nullptr));
        label_3->setText(QApplication::translate("TransformWidget", "Z", nullptr));
        groupBox_2->setTitle(QApplication::translate("TransformWidget", "Rotation", nullptr));
        label_4->setText(QApplication::translate("TransformWidget", "X", nullptr));
        label_5->setText(QApplication::translate("TransformWidget", "Y", nullptr));
        label_6->setText(QApplication::translate("TransformWidget", "Z", nullptr));
        groupBox_3->setTitle(QApplication::translate("TransformWidget", "Scale", nullptr));
        label_7->setText(QApplication::translate("TransformWidget", "X", nullptr));
        label_8->setText(QApplication::translate("TransformWidget", "Y", nullptr));
        label_9->setText(QApplication::translate("TransformWidget", "Z", nullptr));
        label_10->setText(QApplication::translate("TransformWidget", "Transform Component", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TransformWidget: public Ui_TransformWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFORMWIDGET_H
