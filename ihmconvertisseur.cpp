#include "ihmconvertisseur.h"
#include "convertisseur.h"
#include <QDebug>


IHMConvertisseur::IHMConvertisseur(QWidget *parent) : QWidget(parent)
{
    btnQuitter = new QPushButton("Quitter");
    btnConvertir = new QPushButton("Convertir");
    Unite = new QLabel;
    Resultat = new QLabel;
    comboChoix = new QComboBox;
    Saisie = new QLineEdit;
    convert = new Convertisseur();

    //validation de la saisie
    valid = new QDoubleValidator(-50.0, 100.0, 3);
    valid->setLocale(QLocale::c());
    Saisie->setValidator(valid);

    //ajout des différents choix de conversion
    comboChoix->addItem("Celsius -> Farenheit");
    comboChoix->addItem("Farenheit -> Celsius");
    comboChoix->addItem("Mètre -> Yard");
    comboChoix->addItem("Yard -> Mètre");
    comboChoix->addItem("Kilomètre -> Nautique");
    comboChoix->addItem("Nautique -> Kilomètre");
    comboChoix->addItem("Kilomètre/heure -> Noeud");
    comboChoix->addItem("Noeud -> Kilomètre/heure");


    //création de la fenêtre
    QVBoxLayout * vbox = new QVBoxLayout();
    QHBoxLayout * hbox_haut = new QHBoxLayout();
    QHBoxLayout * hbox_bas = new QHBoxLayout();

    //Gestion Hbox haut
    hbox_haut->addWidget(Saisie);
    hbox_haut->addWidget(comboChoix);
    hbox_haut->addWidget(Resultat);
    hbox_haut->addWidget(Unite);

    //Gestion Hbox bas
    hbox_bas->addWidget(btnConvertir);
    hbox_bas->addWidget(btnQuitter);

    //Gestion du vbox
    vbox->addLayout(hbox_haut);
    vbox->addLayout(hbox_bas);

    //application à la fenetre principale
    this->setLayout(vbox);

    connect(btnConvertir, SIGNAL(clicked()), this,SLOT(convertir()));
    connect(comboChoix, SIGNAL(currentIndexChanged(int)), this,SLOT(permuter(int)));
    connect(btnQuitter, SIGNAL(clicked()), this,SLOT(close()));

    connect(Saisie, SIGNAL(textChanged(const QString &)), this, SLOT(convertir()));
}


IHMConvertisseur::~IHMConvertisseur()
{
}



void IHMConvertisseur::convertir(){
    qDebug() << "Convertion";

    int res_int = 0;
    QString str = Saisie->text();
    QValidator::State st = valid->validate(str, res_int);
    qDebug() << st;

    double valeur = Saisie->text().toDouble();
    int index_courant = comboChoix->currentIndex();

    switch(index_courant){

        case 0:
        {
            double result = convert->CelciustoFarenheit(valeur);
            Resultat->setText(QString::number(result));
            Unite->setText("°F");
         break;
        }

        case 1:
        {
                double result2 = convert->FarenheittoCelcius(valeur);
                Resultat->setText(QString::number(result2));
                Unite->setText("°C");
        break;
        }

        case 2:
        {
                double result3 = convert->MetretoYard(valeur);
                Resultat->setText(QString::number(result3));
                Unite->setText("yd");
        break;
        }

        case 3:
        {
                double result4 = convert->YardtoMetre(valeur);
                Resultat->setText(QString::number(result4));
                Unite->setText("m");
        break;
        }

        case 4:
        {
                double result5 = convert->KilometretoNautique(valeur);
                Resultat->setText(QString::number(result5));
                Unite->setText("MN");
        break;
        }

        case 5:
        {
                double result6 = convert->NautiquetoKilometre(valeur);
                Resultat->setText(QString::number(result6));
                Unite->setText("km");
        break;
        }

        case 6:
        {
                double result7 = convert->KilometreheuretoNoeud(valeur);
                Resultat->setText(QString::number(result7));
                Unite->setText("kn");
        break;
        }

        case 7:
        {
                double result8 = convert->NoeudtoKilometreheure(valeur);
                Resultat->setText(QString::number(result8));
                Unite->setText("km/h");
        break;
        }
    }
    this->last_current_index = index_courant;
}


void IHMConvertisseur::permuter(int i){
    qDebug() << "Permutation" << i << "ancien index" << last_current_index;
    bool perm_auto = false;

    if (i == 0 && last_current_index == 1){
        perm_auto = true;
        Unite->setText("°F");
    }

    else if(i == 1 && last_current_index == 0){
        perm_auto = true;
        Unite->setText("°C");
    }

    else if(i == 2 && last_current_index == 3){
        perm_auto = true;
        Unite->setText("m");
    }

    else if(i == 3 && last_current_index == 2) {
        perm_auto = true;
        Unite->setText("yd");
    }

    else if(i == 4 && last_current_index == 5) {
        perm_auto = true;
        Unite->setText("MN");
    }

    else if(i == 5 && last_current_index == 4) {
        perm_auto = true;
        Unite->setText("km");
    }

    else if(i == 6 && last_current_index == 7) {
        perm_auto = true;
        Unite->setText("nd");
    }

    else if(i == 7 && last_current_index == 6) {
        perm_auto = true;
        Unite->setText("km/h");
    }

    this ->last_current_index = comboChoix->currentIndex();

    if (perm_auto){
        QString temp = Resultat->text();
        Resultat->setText(Saisie->text());
        Saisie->setText(temp);
    }
}
