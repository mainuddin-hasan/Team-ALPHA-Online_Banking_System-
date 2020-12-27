#ifndef LOGINPG_PROFILEPG_H
#define LOGINPG_PROFILEPG_H

#include <QDialog>
#include <QDebug>
#include<QMessageBox>
#include<QSqlDatabase>
#include <QSqlQuery>
#include<QString>
#include <QPlainTextEdit>
#include <QSqlQueryModel>
#include<QSqlRecord>
#include<QVBoxLayout>
#include<QLabel>
#include<QFrame>
#include<QPixmap>
#include <QFileDialog>

namespace Ui {
class loginPg_profilePg;
}

class loginPg_profilePg : public QDialog
{
    Q_OBJECT

public:
    explicit loginPg_profilePg(QWidget *parent = nullptr);
    ~loginPg_profilePg();

private slots:
    void on_login_button_clicked();

    void on_creat_account_loginpg_button_clicked();


    void on_creat_button_clicked();





    void on_back_loginpg_button_clicked();

    void on_back_login_button_clicked();



    void on_profile_logout_button_clicked();

    void on_update_acc_button_clicked();

    void on_back_profilepg_button_clicked();

    void on_backDto_profilepg_button_clicked();

    void on_delete_acc_button_clicked();

    void on_backUPto_profilepg_button_clicked();

    void on_cheak_blnc_button_clicked();

    void on_backUPto_profilepg_button_2_clicked();

    void on_update_phone_button_clicked();

    void on_update_phonePg_button_clicked();

    void on_backUP_phoneto_update_button_clicked();

    void on_update_address_button_clicked();

    void on_update_addressPg_button_clicked();

    void on_backUP_address_to_update_acc_button_clicked();

    void on_update_password_button_clicked();

    void on_update_passwordPg_button_clicked();

    void on_backUP_password_to_profilepg_button_clicked();

    void on_delete_acc_button_2_clicked();

    void on_login_button_security_clicked();

    void on_backUP_Relogin_to_profilePg_button_clicked();

    void on_backChkto_profilePg_button_clicked();

    void on_deposite_money_button_clicked();

    void on_deposite_money_confirm_button_clicked();

    void on_backDep_to_cheakBlnc_button_clicked();

    void on_withdraw_money_button_clicked();

    void on_withdraw_money_confirm_button_clicked();

    void on_backWithdraw_to_ChkBlncPg_button_clicked();

    void on_transfer_money_button_clicked();

    void on_login_transfer_security_button_clicked();

    void on_transfer_money_confirm_button_clicked();

    void on_backTransfer_to_ChkBlncPg_button_clicked();

    void on_image_search_link_button_clicked();

    void on_Deposit_history_button_clicked();

    void on_history_button_clicked();

    void on_withdraw_history_button_clicked();

    void on_transfer_history_button_clicked();

    void on_BackHistoryTo_PrfilePg_button_2_clicked();

    void on_backT_Relogin_to_cheakB_button_clicked();

private:
    Ui::loginPg_profilePg *ui;
    QString login_username,login_password,creat_name,creat_address,creat_nid,creat_phone,imag_path,creat_username,creat_password,creat_retype_pass,creat_gender;
    QPixmap p_picture;
    QString update_phone,update_address,update_password,old_password;
    QString delete_username,relogin_username,relogin_password;
    QString transfer_relogin_username,transfer_relogin_password;
    QString account_no;
    double current_balance;
    double current_blnc,deposit_money;
    double current_blncW,withdraw_money;
    double current_blncT,transfer_money;
    double current_blnc_reciver;
    QSqlQueryModel *model,*model1,*model2;
    QSqlDatabase db;

};

#endif // LOGINPG_PROFILEPG_H
