/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_title;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *edit_username;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_7;
    QLineEdit *edit_password;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *button_login;
    QSpacerItem *horizontalSpacer;
    QPushButton *button_register;
    QSpacerItem *horizontalSpacer_3;
    QWidget *page;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout;
    QPushButton *session;
    QPushButton *upload;
    QPushButton *download;
    QPushButton *share;
    QPushButton *pushButton_5;
    QPushButton *fresh;
    QLabel *label_user_name;
    QPushButton *Button_logout;
    QTableWidget *files;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_6;
    QLabel *label;
    QTableWidget *transport;
    QWidget *page_4;
    QTableWidget *files_2;
    QPushButton *shareConfirm;
    QPushButton *shareCancel;
    QWidget *page_5;
    QTableWidget *FriendsList;
    QPushButton *AddFriends;
    QPushButton *StartChat;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(800, 600);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        widget_4 = new QWidget(page_3);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(140, 100, 481, 381));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy);
        widget_4->setMinimumSize(QSize(481, 381));
        widget_4->setMaximumSize(QSize(481, 381));
        verticalLayout_2 = new QVBoxLayout(widget_4);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_title = new QLabel(widget_4);
        label_title->setObjectName(QStringLiteral("label_title"));
        QFont font;
        font.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        font.setPointSize(20);
        label_title->setFont(font);
        label_title->setFrameShape(QFrame::NoFrame);
        label_title->setTextFormat(Qt::RichText);
        label_title->setScaledContents(false);
        label_title->setAlignment(Qt::AlignCenter);
        label_title->setWordWrap(false);
        label_title->setMargin(0);
        label_title->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

        verticalLayout_2->addWidget(label_title);

        widget = new QWidget(widget_4);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMaximumSize(QSize(400, 16777215));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(50, -1, -1, -1);
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font1;
        font1.setFamily(QStringLiteral("Adobe Arabic"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        label_3->setFont(font1);

        horizontalLayout_3->addWidget(label_3);

        horizontalSpacer_6 = new QSpacerItem(15, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        edit_username = new QLineEdit(widget);
        edit_username->setObjectName(QStringLiteral("edit_username"));
        QFont font2;
        font2.setPointSize(10);
        edit_username->setFont(font2);
        edit_username->setMaxLength(16);
        edit_username->setClearButtonEnabled(false);

        horizontalLayout_3->addWidget(edit_username);


        verticalLayout_2->addWidget(widget);

        widget_2 = new QWidget(widget_4);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMaximumSize(QSize(400, 16777215));
        horizontalLayout_4 = new QHBoxLayout(widget_2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(50, -1, -1, -1);
        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        horizontalLayout_4->addWidget(label_4);

        horizontalSpacer_7 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        edit_password = new QLineEdit(widget_2);
        edit_password->setObjectName(QStringLiteral("edit_password"));
        edit_password->setFont(font2);
        edit_password->setMaxLength(16);
        edit_password->setEchoMode(QLineEdit::Password);

        horizontalLayout_4->addWidget(edit_password);


        verticalLayout_2->addWidget(widget_2);

        widget_3 = new QWidget(widget_4);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayout_5 = new QHBoxLayout(widget_3);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        button_login = new QPushButton(widget_3);
        button_login->setObjectName(QStringLiteral("button_login"));
        button_login->setMaximumSize(QSize(150, 50));

        horizontalLayout_5->addWidget(button_login);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        button_register = new QPushButton(widget_3);
        button_register->setObjectName(QStringLiteral("button_register"));
        button_register->setMaximumSize(QSize(150, 50));

        horizontalLayout_5->addWidget(button_register);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout_2->addWidget(widget_3);

        stackedWidget->addWidget(page_3);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        verticalLayout_3 = new QVBoxLayout(page);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        widget_5 = new QWidget(page);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        horizontalLayout = new QHBoxLayout(widget_5);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        session = new QPushButton(widget_5);
        session->setObjectName(QStringLiteral("session"));

        horizontalLayout->addWidget(session);

        upload = new QPushButton(widget_5);
        upload->setObjectName(QStringLiteral("upload"));

        horizontalLayout->addWidget(upload);

        download = new QPushButton(widget_5);
        download->setObjectName(QStringLiteral("download"));

        horizontalLayout->addWidget(download);

        share = new QPushButton(widget_5);
        share->setObjectName(QStringLiteral("share"));

        horizontalLayout->addWidget(share);

        pushButton_5 = new QPushButton(widget_5);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        horizontalLayout->addWidget(pushButton_5);

        fresh = new QPushButton(widget_5);
        fresh->setObjectName(QStringLiteral("fresh"));

        horizontalLayout->addWidget(fresh);

        label_user_name = new QLabel(widget_5);
        label_user_name->setObjectName(QStringLiteral("label_user_name"));

        horizontalLayout->addWidget(label_user_name);

        Button_logout = new QPushButton(widget_5);
        Button_logout->setObjectName(QStringLiteral("Button_logout"));

        horizontalLayout->addWidget(Button_logout);

        fresh->raise();
        upload->raise();
        download->raise();
        share->raise();
        pushButton_5->raise();
        label_user_name->raise();
        Button_logout->raise();
        session->raise();

        verticalLayout_3->addWidget(widget_5);

        files = new QTableWidget(page);
        if (files->columnCount() < 3)
            files->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        files->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        files->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        files->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (files->rowCount() < 1)
            files->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        files->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        files->setItem(0, 0, __qtablewidgetitem4);
        files->setObjectName(QStringLiteral("files"));
        files->horizontalHeader()->setDefaultSectionSize(200);
        files->horizontalHeader()->setMinimumSectionSize(28);
        files->verticalHeader()->setDefaultSectionSize(28);

        verticalLayout_3->addWidget(files);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        verticalLayout_4 = new QVBoxLayout(page_2);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        widget_6 = new QWidget(page_2);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        horizontalLayout_2 = new QHBoxLayout(widget_6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_6 = new QPushButton(widget_6);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_2->addWidget(pushButton_6);

        label = new QLabel(widget_6);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);


        verticalLayout_4->addWidget(widget_6);

        transport = new QTableWidget(page_2);
        if (transport->columnCount() < 3)
            transport->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        transport->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        transport->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        transport->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        transport->setObjectName(QStringLiteral("transport"));
        transport->horizontalHeader()->setCascadingSectionResizes(false);
        transport->horizontalHeader()->setDefaultSectionSize(200);

        verticalLayout_4->addWidget(transport);

        stackedWidget->addWidget(page_2);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        files_2 = new QTableWidget(page_4);
        if (files_2->columnCount() < 3)
            files_2->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        files_2->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        files_2->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        files_2->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        if (files_2->rowCount() < 1)
            files_2->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        files_2->setVerticalHeaderItem(0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        files_2->setItem(0, 0, __qtablewidgetitem12);
        files_2->setObjectName(QStringLiteral("files_2"));
        files_2->setGeometry(QRect(10, 10, 751, 511));
        files_2->horizontalHeader()->setDefaultSectionSize(200);
        files_2->horizontalHeader()->setMinimumSectionSize(28);
        files_2->verticalHeader()->setDefaultSectionSize(28);
        shareConfirm = new QPushButton(page_4);
        shareConfirm->setObjectName(QStringLiteral("shareConfirm"));
        shareConfirm->setGeometry(QRect(450, 530, 181, 41));
        shareCancel = new QPushButton(page_4);
        shareCancel->setObjectName(QStringLiteral("shareCancel"));
        shareCancel->setGeometry(QRect(110, 530, 171, 41));
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        FriendsList = new QTableWidget(page_5);
        if (FriendsList->columnCount() < 2)
            FriendsList->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        FriendsList->setHorizontalHeaderItem(0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        FriendsList->setHorizontalHeaderItem(1, __qtablewidgetitem14);
        FriendsList->setObjectName(QStringLiteral("FriendsList"));
        FriendsList->setGeometry(QRect(60, 60, 421, 512));
        FriendsList->setColumnCount(2);
        FriendsList->horizontalHeader()->setCascadingSectionResizes(false);
        FriendsList->horizontalHeader()->setDefaultSectionSize(200);
        AddFriends = new QPushButton(page_5);
        AddFriends->setObjectName(QStringLiteral("AddFriends"));
        AddFriends->setGeometry(QRect(570, 160, 151, 71));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font3.setPointSize(14);
        AddFriends->setFont(font3);
        StartChat = new QPushButton(page_5);
        StartChat->setObjectName(QStringLiteral("StartChat"));
        StartChat->setGeometry(QRect(570, 290, 151, 71));
        StartChat->setFont(font3);
        stackedWidget->addWidget(page_5);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label_title->setText(QApplication::translate("Widget", "\346\254\242\350\277\216\346\235\245\345\210\260**\344\272\221\347\233\230~", Q_NULLPTR));
        label_3->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        edit_username->setText(QApplication::translate("Widget", "123456", Q_NULLPTR));
        label_4->setText(QApplication::translate("Widget", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        edit_password->setText(QApplication::translate("Widget", "123456", Q_NULLPTR));
        button_login->setText(QApplication::translate("Widget", "\347\231\273\345\275\225", Q_NULLPTR));
        button_register->setText(QApplication::translate("Widget", "\346\263\250\345\206\214", Q_NULLPTR));
        session->setText(QApplication::translate("Widget", "\345\245\275\345\217\213\345\210\227\350\241\250", Q_NULLPTR));
        upload->setText(QApplication::translate("Widget", "\344\270\212\344\274\240", Q_NULLPTR));
        download->setText(QApplication::translate("Widget", "\344\270\213\350\275\275", Q_NULLPTR));
        share->setText(QApplication::translate("Widget", "\345\210\206\344\272\253", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("Widget", "\344\274\240\350\276\223\345\210\227\350\241\250", Q_NULLPTR));
        fresh->setText(QApplication::translate("Widget", "\345\210\267\346\226\260\347\233\256\345\275\225", Q_NULLPTR));
        label_user_name->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\357\274\232", Q_NULLPTR));
        Button_logout->setText(QApplication::translate("Widget", "\347\231\273\345\207\272", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = files->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Widget", "\346\226\207\344\273\266\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = files->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Widget", "\346\226\207\344\273\266\345\244\247\345\260\217", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = files->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Widget", "\344\270\212\344\274\240\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = files->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("Widget", "1", Q_NULLPTR));

        const bool __sortingEnabled = files->isSortingEnabled();
        files->setSortingEnabled(false);
        files->setSortingEnabled(__sortingEnabled);

        pushButton_6->setText(QApplication::translate("Widget", "\350\277\224\345\233\236\346\226\207\344\273\266\347\233\256\345\275\225", Q_NULLPTR));
        label->setText(QString());
        QTableWidgetItem *___qtablewidgetitem4 = transport->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("Widget", "\346\226\207\344\273\266\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = transport->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("Widget", "\346\226\207\344\273\266\345\244\247\345\260\217", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = transport->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QApplication::translate("Widget", "\344\274\240\350\276\223\350\277\233\345\272\246", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = files_2->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QApplication::translate("Widget", "\346\226\207\344\273\266\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = files_2->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QApplication::translate("Widget", "\346\226\207\344\273\266\345\244\247\345\260\217", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = files_2->horizontalHeaderItem(2);
        ___qtablewidgetitem9->setText(QApplication::translate("Widget", "\344\270\212\344\274\240\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = files_2->verticalHeaderItem(0);
        ___qtablewidgetitem10->setText(QApplication::translate("Widget", "1", Q_NULLPTR));

        const bool __sortingEnabled1 = files_2->isSortingEnabled();
        files_2->setSortingEnabled(false);
        files_2->setSortingEnabled(__sortingEnabled1);

        shareConfirm->setText(QApplication::translate("Widget", "\347\241\256\345\256\232", Q_NULLPTR));
        shareCancel->setText(QApplication::translate("Widget", "\345\217\226\346\266\210", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = FriendsList->horizontalHeaderItem(0);
        ___qtablewidgetitem11->setText(QApplication::translate("Widget", "\345\245\275\345\217\213\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = FriendsList->horizontalHeaderItem(1);
        ___qtablewidgetitem12->setText(QApplication::translate("Widget", "\346\266\210\346\201\257\346\221\230\350\246\201", Q_NULLPTR));
        AddFriends->setText(QApplication::translate("Widget", "\346\267\273\345\212\240\345\245\275\345\217\213", Q_NULLPTR));
        StartChat->setText(QApplication::translate("Widget", "\345\274\200\345\247\213\345\257\271\350\257\235", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
