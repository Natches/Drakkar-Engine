/********************************************************************************
** Form generated from reading UI file 'TransformWidget.ui'
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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TransformWidget
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *label_14;
    QLabel *label_31;
    QLabel *label_27;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_11;
    QDoubleSpinBox *spin_PosY_4;
    QLabel *label_12;
    QDoubleSpinBox *spin_PosX_4;
    QLabel *label_13;
    QDoubleSpinBox *spin_PosZ_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_15;
    QDoubleSpinBox *spin_PosY_5;
    QLabel *label_16;
    QDoubleSpinBox *spin_PosX_5;
    QLabel *label_17;
    QDoubleSpinBox *spin_PosZ_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_18;
    QDoubleSpinBox *spin_PosY_6;
    QLabel *label_19;
    QDoubleSpinBox *spin_PosX_6;
    QLabel *label_20;
    QDoubleSpinBox *spin_PosZ_6;

    void setupUi(QWidget *TransformWidget)
    {
        if (TransformWidget->objectName().isEmpty())
            TransformWidget->setObjectName(QStringLiteral("TransformWidget"));
        TransformWidget->resize(314, 109);
        TransformWidget->setMaximumSize(QSize(16777215, 256));
        TransformWidget->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(TransformWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 6, 0, 6);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        label_14 = new QLabel(TransformWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(label_14);

        label_31 = new QLabel(TransformWidget);
        label_31->setObjectName(QStringLiteral("label_31"));

        verticalLayout->addWidget(label_31);

        label_27 = new QLabel(TransformWidget);
        label_27->setObjectName(QStringLiteral("label_27"));

        verticalLayout->addWidget(label_27);


        horizontalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_11 = new QLabel(TransformWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
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
        label_11->setPalette(palette);
        label_11->setStyleSheet(QStringLiteral("color: #EA4C4C;"));
        label_11->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_11);

        spin_PosY_4 = new QDoubleSpinBox(TransformWidget);
        spin_PosY_4->setObjectName(QStringLiteral("spin_PosY_4"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(spin_PosY_4->sizePolicy().hasHeightForWidth());
        spin_PosY_4->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(spin_PosY_4);

        label_12 = new QLabel(TransformWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
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
        label_12->setPalette(palette1);
        label_12->setStyleSheet(QStringLiteral("color: #A2EF44;"));
        label_12->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_12);

        spin_PosX_4 = new QDoubleSpinBox(TransformWidget);
        spin_PosX_4->setObjectName(QStringLiteral("spin_PosX_4"));
        sizePolicy.setHeightForWidth(spin_PosX_4->sizePolicy().hasHeightForWidth());
        spin_PosX_4->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(spin_PosX_4);

        label_13 = new QLabel(TransformWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
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
        label_13->setPalette(palette2);
        label_13->setStyleSheet(QStringLiteral("color: #24BDDF"));
        label_13->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_13);

        spin_PosZ_4 = new QDoubleSpinBox(TransformWidget);
        spin_PosZ_4->setObjectName(QStringLiteral("spin_PosZ_4"));
        sizePolicy.setHeightForWidth(spin_PosZ_4->sizePolicy().hasHeightForWidth());
        spin_PosZ_4->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(spin_PosZ_4);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_15 = new QLabel(TransformWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
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
        label_15->setPalette(palette3);
        label_15->setStyleSheet(QStringLiteral("color: #EA4C4C;"));
        label_15->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_15);

        spin_PosY_5 = new QDoubleSpinBox(TransformWidget);
        spin_PosY_5->setObjectName(QStringLiteral("spin_PosY_5"));
        sizePolicy.setHeightForWidth(spin_PosY_5->sizePolicy().hasHeightForWidth());
        spin_PosY_5->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(spin_PosY_5);

        label_16 = new QLabel(TransformWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
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
        label_16->setPalette(palette4);
        label_16->setStyleSheet(QStringLiteral("color: #A2EF44;"));
        label_16->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_16);

        spin_PosX_5 = new QDoubleSpinBox(TransformWidget);
        spin_PosX_5->setObjectName(QStringLiteral("spin_PosX_5"));
        sizePolicy.setHeightForWidth(spin_PosX_5->sizePolicy().hasHeightForWidth());
        spin_PosX_5->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(spin_PosX_5);

        label_17 = new QLabel(TransformWidget);
        label_17->setObjectName(QStringLiteral("label_17"));
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
        label_17->setPalette(palette5);
        label_17->setStyleSheet(QStringLiteral("color: #24BDDF"));
        label_17->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_17);

        spin_PosZ_5 = new QDoubleSpinBox(TransformWidget);
        spin_PosZ_5->setObjectName(QStringLiteral("spin_PosZ_5"));
        sizePolicy.setHeightForWidth(spin_PosZ_5->sizePolicy().hasHeightForWidth());
        spin_PosZ_5->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(spin_PosZ_5);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_18 = new QLabel(TransformWidget);
        label_18->setObjectName(QStringLiteral("label_18"));
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
        label_18->setPalette(palette6);
        label_18->setStyleSheet(QStringLiteral("color: #EA4C4C;"));
        label_18->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_18);

        spin_PosY_6 = new QDoubleSpinBox(TransformWidget);
        spin_PosY_6->setObjectName(QStringLiteral("spin_PosY_6"));
        sizePolicy.setHeightForWidth(spin_PosY_6->sizePolicy().hasHeightForWidth());
        spin_PosY_6->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(spin_PosY_6);

        label_19 = new QLabel(TransformWidget);
        label_19->setObjectName(QStringLiteral("label_19"));
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
        label_19->setPalette(palette7);
        label_19->setStyleSheet(QStringLiteral("color: #A2EF44;"));
        label_19->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_19);

        spin_PosX_6 = new QDoubleSpinBox(TransformWidget);
        spin_PosX_6->setObjectName(QStringLiteral("spin_PosX_6"));
        sizePolicy.setHeightForWidth(spin_PosX_6->sizePolicy().hasHeightForWidth());
        spin_PosX_6->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(spin_PosX_6);

        label_20 = new QLabel(TransformWidget);
        label_20->setObjectName(QStringLiteral("label_20"));
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
        label_20->setPalette(palette8);
        label_20->setStyleSheet(QStringLiteral("color: #24BDDF"));
        label_20->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_20);

        spin_PosZ_6 = new QDoubleSpinBox(TransformWidget);
        spin_PosZ_6->setObjectName(QStringLiteral("spin_PosZ_6"));
        sizePolicy.setHeightForWidth(spin_PosZ_6->sizePolicy().hasHeightForWidth());
        spin_PosZ_6->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(spin_PosZ_6);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);


        retranslateUi(TransformWidget);

        QMetaObject::connectSlotsByName(TransformWidget);
    } // setupUi

    void retranslateUi(QWidget *TransformWidget)
    {
        TransformWidget->setWindowTitle(QApplication::translate("TransformWidget", "Form", nullptr));
        label_14->setText(QApplication::translate("TransformWidget", "Position:", nullptr));
        label_31->setText(QApplication::translate("TransformWidget", "Rotation:", nullptr));
        label_27->setText(QApplication::translate("TransformWidget", "Scale:", nullptr));
        label_11->setText(QApplication::translate("TransformWidget", "X", nullptr));
        label_12->setText(QApplication::translate("TransformWidget", "Y", nullptr));
        label_13->setText(QApplication::translate("TransformWidget", "Z", nullptr));
        label_15->setText(QApplication::translate("TransformWidget", "X", nullptr));
        label_16->setText(QApplication::translate("TransformWidget", "Y", nullptr));
        label_17->setText(QApplication::translate("TransformWidget", "Z", nullptr));
        label_18->setText(QApplication::translate("TransformWidget", "X", nullptr));
        label_19->setText(QApplication::translate("TransformWidget", "Y", nullptr));
        label_20->setText(QApplication::translate("TransformWidget", "Z", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TransformWidget: public Ui_TransformWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFORMWIDGET_H
