#include "pokemondata.h"
#include <QPixmap>
#include <QString>
#include <QImage>
#include <QStringList>
#include <QFile>
#include <QDir>
#include <QTextStream>
#define Pokemon_Max 386

// Maximum value for a female Pok�mon is 254 (MON_FEMALE) which is 100% female.
// 255 (MON_GENDERLESS) is reserved for genderless Pok�mon.
#define PERCENT_FEMALE(percent) min(254, ((percent * 255) / 100))
Pokemondata::Pokemondata()
{
    typedef struct PokemonData
    {
       QStringList pokemonName;
       int pokeDexNum;
       int pokeNatNum;
       int HP;
       int Defense;
       int Speed;
       int Special_Attack;
       int Special_Defense;
       QString pokedexEntry;
       QPixmap frontImage;
       QPixmap backImage;
       QImage front;
       QImage back;
       QStringList type1;
       QStringList type2;
       QStringList item1;
       QStringList item2;
       QStringList pokemonGender;
       int friendship;
       QStringList eggGroup1;
       QStringList eggGroup2;
       QStringList ability1;
       QStringList ability2;
       int evHP;
       int evDefense;
       int evSpeed;
       int evSpecial_Attack;
       int evSpecial_Defense;
       QStringList evolutionMethod;
    }Pokemon;
}
QFile openFile(QFile file)
{
    QTextStream in(&file);
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text))



    while(!in.atEnd())
    {
        QString line = in.readLine();
    }

}
Pokemondata *JsonImporter()
{

}
Pokemondata *JsonExporter()
{

}
Pokemondata *makeInfo()
{
  QDir baseFolder;
  QFile pokemonFile("/src/pokemon.c");
  QFile pokemonFrontImage("/graphics/pokemon/front_pics/");
  QFile pokemonBackImage("/graphics/pokemon/back_pics/");
  QFile pokemonIconsImage("/graphics/pokemon/icons/");
  QFile pokemonStatsHeader("/src/data/pokemon/base_stats.h");
  QFile pokemonFileHeader("/src/data/graphics/pokemon.h");
  QFile pokedex_entries("/src/data/pokemon/pokedex_entries.h");
  QFile pokemonPallets("/graphics/pokemon/palletes/");
  QFile pokemonIconPallets("/graphics/pokemon/icon_pallets");

}
