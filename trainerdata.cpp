#include "trainerdata.h"
#include <QString>
#include <QStringList>
#define Trainer_Max 40
trainerdata::trainerdata()
{
    typedef struct TrainerData
    {
      QStringList Name;
      QStringList TrainerClass;
      QStringList encounterMusic;
      QStringList trainerPic;
      QString Items;
      bool doubleBattles;
      QStringList aiFlags;
      int partySize;
    }Trainer;

}

trainerdata *Jsonimporter()
{

}
trainerdata *Jsonexporter()
{

}
trainerdata *makeinfo()
{

}
