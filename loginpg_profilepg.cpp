#include "loginpg_profilepg.h"
#include "ui_loginpg_profilepg.h"
#include "mainwindow.h"
#include "QAbstractItemModel"
MainWindow *main_window;

loginPg_profilePg::loginPg_profilePg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginPg_profilePg)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/MAINUDDIN/Documents/New folder/Bank_management_project/bank_user_database.db");

    db.open();
    qDebug()<<db.isOpen();

}

loginPg_profilePg::~loginPg_profilePg()
{
    db.close();
    delete ui;
}


void loginPg_profilePg::on_login_button_clicked()
{
    login_username = ui->username_login_input->text();
    login_password = ui->password_login_input->text();

    QSqlQuery qurey;
    qDebug()<<qurey.exec("SELECT * FROM bank_user_data WHERE username = '"+login_username+"' AND password = '"+login_password+"'");

    if(qurey.next())
    {
        ui->stackedWidget->setCurrentIndex(2);

        ui->profile_name_level->setText(qurey.value(0).toString());
        ui->profile_address_level->setText(qurey.value(1).toString());
        ui->profile_gender_level->setText(qurey.value(7).toString());
        ui->profile_phone_level->setText(qurey.value(3).toString());
        ui->profile_nid_level->setText(qurey.value(2).toString());

        QPixmap p_picture(qurey.value(10).toString());
        ui->profile_pic_level->setPixmap(p_picture);

        current_balance = qurey.value(8).toDouble();
        //qDebug()<<a;
        ui->current_balance_level->setNum(current_balance);

    }
    else
    {
        QMessageBox::warning(this,"login","wrong username password!!!");
    }
    ui->username_login_input->clear();
    ui->password_login_input->clear();

}



void loginPg_profilePg::on_creat_account_loginpg_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void loginPg_profilePg::on_image_search_link_button_clicked()
{
    imag_path = QFileDialog::getOpenFileName(
                this,
                tr("Open Image"),
                "",
                tr("JPEG (*.jpg *.jpeg);;PNG (*.png)" )
                );

   ui->profile_photo_link_input->setText(imag_path);
}

void loginPg_profilePg::on_creat_button_clicked()
{
    creat_name = ui->creat_name_input->text();
    creat_address = ui->creat_address_input->text();
    creat_nid = ui->creat_nid_input->text();
    creat_phone = ui->creat_phone_input->text();
    creat_username = ui->creat_user_name_input->text();
    creat_password = ui->creat_password_input->text();
    creat_retype_pass = ui->creat_retype_pass_input->text();


    if(ui->male_button->isChecked())
    {
        creat_gender = "male";
    }
    else
    {
        creat_gender = "female";
    }
    QSqlQuery query6;
    query6.exec("SELECT * FROM bank_user_data WHERE username='"+creat_username+"'");
    if(query6.next())
    {
        QMessageBox::warning(this,"creat","username already in use");
        ui->creat_user_name_input->clear();
        ui->creat_password_input->clear();
        ui->creat_retype_pass_input->clear();
    }
    else
    {
        //QSqlQuery query;
        qDebug()<<query6.exec("INSERT INTO bank_user_data (name, address, NID, phone, username, password, retype_pass, gender ,image_path) VALUES ('"+creat_name+"' , '"+creat_address+"' , '"+creat_nid+"' , '"+creat_phone+"' , '"+creat_username+"' , '"+creat_password+"' , '"+creat_retype_pass+"' , '"+creat_gender+"' , '"+imag_path+"')");
        QMessageBox::information(this,"creat","creat is successful,please login");
        ui->creat_name_input->clear();
        ui->creat_address_input->clear();
        ui->creat_nid_input->clear();
        ui->creat_phone_input->clear();
        ui->creat_user_name_input->clear();
        ui->creat_password_input->clear();
        ui->creat_retype_pass_input->clear();
        ui->profile_photo_link_input->clear();
    }

}


//Back to mainwindow
void loginPg_profilePg::on_back_loginpg_button_clicked()
{
    hide();
    main_window = new MainWindow(this);
    main_window->show();
}

void loginPg_profilePg::on_back_login_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void loginPg_profilePg::on_profile_logout_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void loginPg_profilePg::on_update_acc_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void loginPg_profilePg::on_back_profilepg_button_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void loginPg_profilePg::on_delete_acc_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void loginPg_profilePg::on_backDto_profilepg_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void loginPg_profilePg::on_backUPto_profilepg_button_clicked()
{
        ui->stackedWidget->setCurrentIndex(2);
}

void loginPg_profilePg::on_cheak_blnc_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void loginPg_profilePg::on_backUPto_profilepg_button_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


//update acc page to up phone
void loginPg_profilePg::on_update_phone_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);

}

void loginPg_profilePg::on_update_phonePg_button_clicked()
{
    update_phone = ui->update_phone_input->text();

    QSqlQuery qurey;
    qurey.exec("UPDATE bank_user_data SET phone='"+update_phone+"' WHERE username='"+login_username+"'");

    QMessageBox::information(this,"update","Updated successfully");

    QSqlQuery qurey1;
    qDebug()<<qurey1.exec("SELECT * FROM bank_user_data WHERE username = '"+login_username+"' AND password = '"+login_password+"'");

    if(qurey1.next())
    {

        ui->profile_phone_level->setText(qurey1.value(3).toString());

    }
    ui->stackedWidget->setCurrentIndex(2);
}

void loginPg_profilePg::on_backUP_phoneto_update_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


//update acc page to up address pg
void loginPg_profilePg::on_update_address_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void loginPg_profilePg::on_update_addressPg_button_clicked()
{
    update_address = ui->update_address_input->text();

    QSqlQuery qurey;
    qurey.exec("UPDATE bank_user_data SET address='"+update_address+"' WHERE username='"+login_username+"'");
    QMessageBox::information(this,"update","Updated successfully");

    QSqlQuery qurey2;
    qDebug()<<qurey2.exec("SELECT * FROM bank_user_data WHERE username = '"+login_username+"' AND password = '"+login_password+"'");

    if(qurey2.next())
    {

        ui->profile_address_level->setText(qurey2.value(1).toString());

    }
    ui->stackedWidget->setCurrentIndex(2);
}

void loginPg_profilePg::on_backUP_address_to_update_acc_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


//update acc page to up password pg
void loginPg_profilePg::on_update_password_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void loginPg_profilePg::on_update_passwordPg_button_clicked()
{
    old_password = ui->update_old_password_input->text();
    update_password = ui->update_password_input->text();

    QSqlQuery qurey;
    qDebug()<<qurey.exec("SELECT * FROM bank_user_data WHERE password = '"+old_password+"'");
    if(qurey.next())
    {
      //QSqlQuery qurey;
      qurey.exec("UPDATE bank_user_data SET password='"+update_password+"' WHERE username='"+login_username+"'");
      QMessageBox::information(this,"update","Updated successfully");
    }
    else
    {
        QMessageBox::warning(this,"update","Incorrect Old Password");
    }
    ui->update_old_password_input->clear();
    ui->update_password_input->clear();

}

void loginPg_profilePg::on_backUP_password_to_profilepg_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


//Delete account
void loginPg_profilePg::on_delete_acc_button_2_clicked()
{
    delete_username = ui->username_input_delete->text();


    QSqlQuery qurey;
    qurey.exec("Delete from bank_user_data where username='"+delete_username+"'");

    QMessageBox::information(this,"delete","Deleted successfully");
    ui->username_input_delete->clear();
}

//relogin account
void loginPg_profilePg::on_login_button_security_clicked()
{
    relogin_username = ui->update_old_username_input_security->text();
    relogin_password = ui->update_old_password_input_security->text();

    //QSqlQuery qurey;
    //qDebug()<<qurey.exec("SELECT * FROM bank_user_data WHERE username = '"+relogin_username+"' AND password = '"+relogin_password+"'");
    if(relogin_username==login_username && relogin_password==login_password)
    {
        ui->stackedWidget->setCurrentIndex(4);

    }
    else
    {
        QMessageBox::warning(this,"relogin","wrong username password!!!");
    }
    ui->update_old_username_input_security->clear();
    ui->update_old_password_input_security->clear();
}

void loginPg_profilePg::on_backUP_Relogin_to_profilePg_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void loginPg_profilePg::on_backChkto_profilePg_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

//cheak balance to Deposit and back
void loginPg_profilePg::on_deposite_money_button_clicked()
{

    ui->stackedWidget->setCurrentIndex(10);

}
void loginPg_profilePg::on_deposite_money_confirm_button_clicked()
{

    deposit_money = ui->deposite_amount_input->text().toDouble();
    //for user history
    QSqlQuery qurey10;
    QString s5 = QString::number(deposit_money);
    qDebug()<<qurey10.exec("INSERT INTO user_deposit_history (depositMoney,depositTime,depositDate,Dusername) VALUES ('"+s5+"' , time('now') , date('now') , '"+login_username+"')");

    QSqlQuery qurey3;
    current_blnc = ui->current_balance_level->text().toDouble();
    //qDebug()<<current_blnc;
    if(deposit_money>=0)
    {
        current_blnc =current_blnc + deposit_money;
        //qDebug()<<current_blnc;
        ui->current_balance_level->setNum(current_blnc);

        QString s = QString::number(current_blnc);
        qurey3.exec("UPDATE bank_user_data SET Balance= '"+s+"' WHERE username='"+login_username+"'");
        QMessageBox::information(this,"deposit","Deposited Successfully");
        ui->stackedWidget->setCurrentIndex(5);
    }
    else
    {
        QMessageBox::warning(this,"deposit","Invalid Amount!!!");
    }
    ui->deposite_amount_input->clear();

}

void loginPg_profilePg::on_backDep_to_cheakBlnc_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}


//cheak balance to Withdraw and back
void loginPg_profilePg::on_withdraw_money_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void loginPg_profilePg::on_withdraw_money_confirm_button_clicked()
{
    withdraw_money = ui->withdraw_money_input->text().toDouble();
    //for user history
    QSqlQuery qurey11;
    QString s6 = QString::number(withdraw_money);
    qDebug()<<qurey11.exec("INSERT INTO user_withdraw_history (withdrawMoney,withdrawTime,withdrawDate,Wusername) VALUES ('"+s6+"' , time('now') , date('now') , '"+login_username+"')");
    //----
    QSqlQuery qurey5;
    current_blncW = ui->current_balance_level->text().toDouble();
    qDebug()<<current_blncW;
    if(withdraw_money<=current_blncW)
    {

        current_blncW = current_blncW - withdraw_money;
        qDebug()<<current_blncW;
        ui->current_balance_level->setNum(current_blncW);
        QMessageBox::information(this,"withdraw","withdraw is Successfull");
        QString s1 = QString::number(current_blncW);
        qurey5.exec("UPDATE bank_user_data SET Balance= '"+s1+"' WHERE username='"+login_username+"'");
        ui->stackedWidget->setCurrentIndex(5);
    }
    else
    {
        QMessageBox::warning(this,"withdraw","Insufficient balance!");
    }
     ui->withdraw_money_input->clear();

}

void loginPg_profilePg::on_backWithdraw_to_ChkBlncPg_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

//Chaek balance to transfer money
void loginPg_profilePg::on_transfer_money_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}

void loginPg_profilePg::on_login_transfer_security_button_clicked()
{
    transfer_relogin_username = ui->transfer_username_input_security->text();
    transfer_relogin_password = ui->transfer_password_input_security->text();

    if(transfer_relogin_username == login_username && transfer_relogin_password == login_password)
    {


            ui->stackedWidget->setCurrentIndex(12);


    }
    else
    {
        QMessageBox::warning(this,"login","wrong username password!!!");
    }
    ui->transfer_username_input_security->clear();
    ui->transfer_password_input_security->clear();
}

void loginPg_profilePg::on_transfer_money_confirm_button_clicked()
{
    transfer_money = ui->transfer_amount_input->text().toDouble();
    account_no = ui->transfer_acc_No_input->text();
    //for user history
    QSqlQuery qurey12;
    QString s7 = QString::number(transfer_money);
    qDebug()<<qurey12.exec("INSERT INTO user_transfer_history (transferMoney,transferTime,transferDate,Tusername) VALUES ('"+s7+"' , time('now') , date('now') , '"+login_username+"')");
    //-----
    QSqlQuery qurey8;
    qDebug()<<qurey8.exec("SELECT * FROM bank_user_data WHERE account_no = '"+account_no+"'");
    if(qurey8.next())
    {
        current_blncT = ui->current_balance_level->text().toDouble();

        if(current_blncT>=transfer_money)
        {
            current_blnc_reciver = qurey8.value(8).toDouble();
            current_blnc_reciver = current_blnc_reciver + transfer_money;
            QString s3 = QString::number(current_blnc_reciver);
            qurey8.exec("UPDATE bank_user_data SET Balance= '"+s3+"' WHERE account_no= '"+account_no+"'");

            current_blncT = current_blncT - transfer_money;
            qDebug()<<current_blncT;
            ui->current_balance_level->setNum(current_blncT);
            QSqlQuery qurey9;
            QString s4 = QString::number(current_blncT);
            qurey9.exec("UPDATE bank_user_data SET Balance= '"+s4+"' WHERE username= '"+login_username+"'");
            QMessageBox::information(this,"transfer","trasfered Successfully");
            ui->stackedWidget->setCurrentIndex(5);
        }
        else
        {
            QMessageBox::warning(this,"warning","Insufficient Balance");
        }

    }
    else
    {
        QMessageBox::warning(this,"warning","Account Doesn't Exist");
    }
    ui->transfer_amount_input->clear();
    ui->transfer_acc_No_input->clear();


}

void loginPg_profilePg::on_backTransfer_to_ChkBlncPg_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}


void loginPg_profilePg::on_Deposit_history_button_clicked()
{

    this->model = new QSqlQueryModel();
    model->setQuery("SELECT depositMoney,depositDate,depositTime FROM user_deposit_history WHERE Dusername = '"+login_username+"'");
    ui->tableView_for_history->setModel(model);

}

void loginPg_profilePg::on_history_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);
}

void loginPg_profilePg::on_withdraw_history_button_clicked()
{
    this->model1 = new QSqlQueryModel();
    model1->setQuery("SELECT withdrawMoney,withdrawDate,withdrawTime FROM user_withdraw_history WHERE Wusername = '"+login_username+"'");
    ui->tableView_for_history->setModel(model1);
}


void loginPg_profilePg::on_transfer_history_button_clicked()
{
    this->model2 = new QSqlQueryModel();
    model2->setQuery("SELECT transferMoney,transferDate,transferTime FROM user_transfer_history WHERE Tusername = '"+login_username+"'");
    ui->tableView_for_history->setModel(model2);
}

void loginPg_profilePg::on_BackHistoryTo_PrfilePg_button_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void loginPg_profilePg::on_backT_Relogin_to_cheakB_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}
