#pragma once
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

using namespace std;

struct Monster
{
    string Name;
    int Level;
    string Class;
    string IdleIMG;
    vector <string> MoveIMG;
    vector <string> AttackIMG;
    string Bullet;
    int AttackRange;
    int AttackSpeed;
    int MonsterWidth;
    int MonsterHeight;
    int MoveSpeed = 0;
    int BaseHp = 0;
    int BaseAtk = 0;
    int BaseDef = 0;
    int BaseAccuracy = 0;
    int BaseCritChance = 0;
    int HpPerLevel = 0;
    int AtkPerLevel = 0;
    int DefPerLevel = 0;
    int AccuracyPerLevel = 0;
    int CritChancePerLevel = 0;
    int UpgradeCost = 0;
    Monster();
    Monster(string _Name,
            int _Lv,
            string _Class,
            string _IdleIMG,
            vector <string> _MoveIMG,
            vector <string> _AttackIMG,
            int _AttackRange,
            int _AttackSpeed,
            int _MonsterWidth,
            int _MonsterHeight,
            int _BaseMoveSpeed,
            int _BaseHp,
            int _BaseAtk,
            int _BaseDef,
            int _BaseAccuracy,
            int _BaseCritChance,
            int _HpPerLevel,
            int _AtkPerLevel,
            int _DefPerLevel,
            int _AccuracyPerLevel,
            int _CritChancePerLevel,
            int _UpgradeCost)
    {
        Name = _Name;
        Level = _Lv;
        Class = _Class;
        IdleIMG = _IdleIMG;
        for(int i = 0; i < _MoveIMG.size(); i++)
        {
            MoveIMG.push_back(_MoveIMG[i]);
        }
        for(int i = 0; i < _AttackIMG.size(); i++)
        {
            AttackIMG.push_back(_AttackIMG[i]);
        }
        BaseHp = _BaseHp;
        BaseAtk = _BaseAtk;
        BaseDef = _BaseDef;
        MoveSpeed = _BaseMoveSpeed;
        BaseAccuracy = _BaseAccuracy;
        BaseCritChance = _BaseCritChance;
        HpPerLevel = _HpPerLevel;
        AtkPerLevel = _AtkPerLevel;
        DefPerLevel = _DefPerLevel;
        AccuracyPerLevel = _AccuracyPerLevel;
        CritChancePerLevel = _CritChancePerLevel;
        UpgradeCost = _UpgradeCost;
        AttackRange =_AttackRange,
        MonsterWidth = _MonsterWidth,
        MonsterHeight = _MonsterHeight;
        AttackSpeed = _AttackSpeed;
    }
    Monster(string _Name,
            int _Lv,
            string _Class,
            string _IdleIMG,
            vector <string> _MoveIMG,
            vector <string> _AttackIMG,
            string _Bullet,
            int _AttackRange,
            int _AttackSpeed,
            int _MonsterWidth,
            int _MonsterHeight,
            int _BaseMoveSpeed,
            int _BaseHp,
            int _BaseAtk,
            int _BaseDef,
            int _BaseAccuracy,
            int _BaseCritChance,
            int _HpPerLevel,
            int _AtkPerLevel,
            int _DefPerLevel,
            int _AccuracyPerLevel,
            int _CritChancePerLevel,
            int _UpgradeCost)
    {
        Name = _Name;
        Level = _Lv;
        Class = _Class;
        Bullet = _Bullet;
        IdleIMG = _IdleIMG;
        for(int i = 0; i < _MoveIMG.size(); i++)
        {
            MoveIMG.push_back(_MoveIMG[i]);
        }
        for(int i = 0; i < _AttackIMG.size(); i++)
        {
            AttackIMG.push_back(_AttackIMG[i]);
        }
        BaseHp = _BaseHp;
        BaseAtk = _BaseAtk;
        BaseDef = _BaseDef;
        MoveSpeed = _BaseMoveSpeed;
        BaseAccuracy = _BaseAccuracy;
        BaseCritChance = _BaseCritChance;
        HpPerLevel = _HpPerLevel;
        AtkPerLevel = _AtkPerLevel;
        DefPerLevel = _DefPerLevel;
        AccuracyPerLevel = _AccuracyPerLevel;
        CritChancePerLevel = _CritChancePerLevel;
        UpgradeCost = _UpgradeCost;
        AttackRange =_AttackRange,
        MonsterWidth = _MonsterWidth,
        MonsterHeight = _MonsterHeight;
        AttackSpeed = _AttackSpeed;
    }
    Monster(string _Name,
            int _Lv,
            string _Class,
            string _IdleIMG,
            vector <string> _MoveIMG,
            vector <string> _AttackIMG,
            int _AttackRange,
            int _AttackSpeed,
            int _MonsterWidth,
            int _MonsterHeight,
            int _BaseMoveSpeed,
            int _BaseHp,
            int _BaseAtk,
            int _BaseDef,
            int _BaseAccuracy,
            int _BaseCritChance)
    {
        Name = _Name;
        Level = _Lv;
        Class = _Class;
        IdleIMG = _IdleIMG;
        for(int i = 0; i < _MoveIMG.size(); i++)
        {
            MoveIMG.push_back(_MoveIMG[i]);
        }
        for(int i = 0; i < _AttackIMG.size(); i++)
        {
            AttackIMG.push_back(_AttackIMG[i]);
        }
        BaseHp = _BaseHp;
        BaseAtk = _BaseAtk;
        BaseDef = _BaseDef;
        MoveSpeed = _BaseMoveSpeed;
        BaseAccuracy = _BaseAccuracy;
        BaseCritChance = _BaseCritChance;
        HpPerLevel = 0;
        AtkPerLevel = 0;
        DefPerLevel = 0;
        AccuracyPerLevel = 0;
        CritChancePerLevel = 0;
        UpgradeCost = 0;
        AttackRange =_AttackRange,
        MonsterWidth = _MonsterWidth,
        MonsterHeight = _MonsterHeight;
        AttackSpeed = _AttackSpeed;
    }
    Monster(string _Name,
            int _Lv,
            string _Class,
            string _Bullet,
            string _IdleIMG,
            vector <string> _MoveIMG,
            vector <string> _AttackIMG,
            int _AttackRange,
            int _AttackSpeed,
            int _MonsterWidth,
            int _MonsterHeight,
            int _BaseMoveSpeed,
            int _BaseHp,
            int _BaseAtk,
            int _BaseDef,
            int _BaseAccuracy,
            int _BaseCritChance)
    {
        Name = _Name;
        Level = _Lv;
        Class = _Class;
        Bullet = _Bullet;
        for(int i = 0; i < _MoveIMG.size(); i++)
        {
            MoveIMG.push_back(_MoveIMG[i]);
        }
        for(int i = 0; i < _AttackIMG.size(); i++)
        {
            AttackIMG.push_back(_AttackIMG[i]);
        }
        BaseHp = _BaseHp;
        BaseAtk = _BaseAtk;
        BaseDef = _BaseDef;
        MoveSpeed = _BaseMoveSpeed;
        BaseAccuracy = _BaseAccuracy;
        BaseCritChance = _BaseCritChance;
        HpPerLevel = 0;
        AtkPerLevel = 0;
        DefPerLevel = 0;
        AccuracyPerLevel = 0;
        CritChancePerLevel = 0;
        UpgradeCost = 0;
        AttackRange =_AttackRange,
        MonsterWidth = _MonsterWidth,
        MonsterHeight = _MonsterHeight;
        AttackSpeed = _AttackSpeed;
    }
    void LevelUp()
    {
        if(Level < 10)
        {
            Level++;
            BaseAtk += AtkPerLevel;
            BaseHp += HpPerLevel;
            BaseDef += DefPerLevel;
            BaseAccuracy = min(BaseAccuracy + AccuracyPerLevel, 100);
            BaseCritChance = min(BaseCritChance + CritChancePerLevel, 100);
        }
    }
};

//
//
//
//
//
//
//Monster cua Player
const Monster Liquiz  ("Liquiz", 1, "Melee", "Slime\\SlimeIdle.png",
{
    "Slime\\Slime1.png", "Slime\\Slime2.png", "Slime\\Slime3.png", "Slime\\Slime4.png",
    "Slime\\Slime5.png", "Slime\\Slime6.png", "Slime\\Slime7.png", "Slime\\Slime8.png"
},
{"Slime\\SlimeAttack1.png", "Slime\\SlimeAttack2.png"}, 0, 5, 100, 100, 10,
400, 25, 3, 65, 20,
40, 4, 2, 2, 2, 350);


const Monster Eater ("Eater", 1, "Melee", "Carnitree\\CarnitreeIdle.png",
{
    "Carnitree\\Carnitree1.png", "Carnitree\\Carnitree2.png", "Carnitree\\Carnitree3.png",
    "Carnitree\\Carnitree4.png", "Carnitree\\Carnitree5.png", "Carnitree\\Carnitree6.png",
    "Carnitree\\Carnitree7.png", "Carnitree\\Carnitree8.png"
},
{"Carnitree\\CarnitreeAttack1.png", "Carnitree\\CarnitreeAttack2.png"}, 0, 7, 100, 100, 8,
450, 33 , 3, 65, 20,
40, 5, 1, 1, 4, 400
                    );


const Monster Magma ("Magma", 1, "Melee", "Magma\\MagmaIdle.png",
{
    "Magma\\Magma1.png", "Magma\\Magma2.png", "Magma\\Magma3.png",
    "Magma\\Magma4.png", "Magma\\Magma5.png", "Magma\\Magma6.png",
    "Magma\\Magma7.png", "Magma\\Magma8.png"
},
{"Magma\\MagmaAttack1.png", "Magma\\MagmaAttack2.png"}, 0, 7, 110, 110, 10,
700, 32, 5, 60, 20,
45, 5, 3, 2, 3, 500
                    );

const Monster Crops ("Crops", 1, "Melee", "Crops\\CropsIdle.png",
{
    "Crops\\Crops1.png", "Crops\\Crops2.png", "Crops\\Crops3.png",
    "Crops\\Crops4.png", "Crops\\Crops5.png", "Crops\\Crops6.png",
    "Crops\\Crops7.png", "Crops\\Crops8.png"
},
{"Crops\\CropsAttack1.png", "Crops\\CropsAttack2.png"}, 0, 6, 110, 110, 7,
700, 45, 5, 60, 25,
30, 7, 2, 1, 4, 500
                    );
//
//
//
//
//
//
//
//
//
//
//
//
//
//

//Monster cua Enemy
const Monster Squishee ("Squishee", 1, "Melee", "Slime\\SlimeIdleEnemy.png",
{
    "Slime\\SlimeEnemy1.png", "Slime\\SlimeEnemy2.png", "Slime\\SlimeEnemy3.png", "Slime\\SlimeEnemy4.png",
    "Slime\\SlimeEnemy5.png", "Slime\\SlimeEnemy6.png", "Slime\\SlimeEnemy7.png", "Slime\\SlimeEnemy8.png"
},
{"Slime\\SlimeAttackEnemy1.png", "Slime\\SlimeAttackEnemy2.png"}, 0, 5, 100, 100, 10,
300, 15, 3, 60, 15);

const Monster Bubble ("Bubble", 1, "Melee", "Slime\\SlimeIdleEnemy.png",
{
    "Slime\\SlimeEnemy1.png", "Slime\\SlimeEnemy2.png", "Slime\\SlimeEnemy3.png", "Slime\\SlimeEnemy4.png",
    "Slime\\SlimeEnemy5.png", "Slime\\SlimeEnemy6.png", "Slime\\SlimeEnemy7.png", "Slime\\SlimeEnemy8.png"
},
{"Slime\\SlimeAttackEnemy1.png", "Slime\\SlimeAttackEnemy2.png"}, 0, 5, 100, 100, 10,
400, 25, 3, 65, 15);

const Monster Slimy ("Slimy", 2, "Melee", "Slime\\SlimeIdleEnemy.png",
{
    "Slime\\SlimeEnemy1.png", "Slime\\SlimeEnemy2.png", "Slime\\SlimeEnemy3.png", "Slime\\SlimeEnemy4.png",
    "Slime\\SlimeEnemy5.png", "Slime\\SlimeEnemy6.png", "Slime\\SlimeEnemy7.png", "Slime\\SlimeEnemy8.png"
},
{"Slime\\SlimeAttackEnemy1.png", "Slime\\SlimeAttackEnemy2.png"}, 0, 5, 100, 100, 10,
600, 30, 4, 65, 15);

const Monster Drowning ("Drowning", 3, "Melee", "Slime\\SlimeIdleEnemy.png",
{
    "Slime\\SlimeEnemy1.png", "Slime\\SlimeEnemy2.png", "Slime\\SlimeEnemy3.png", "Slime\\SlimeEnemy4.png",
    "Slime\\SlimeEnemy5.png", "Slime\\SlimeEnemy6.png", "Slime\\SlimeEnemy7.png", "Slime\\SlimeEnemy8.png"
},
{"Slime\\SlimeAttackEnemy1.png", "Slime\\SlimeAttackEnemy2.png"}, 0, 5, 100, 100, 10,
700, 35, 5, 65, 15);


const Monster Hungtree ("Hungtree", 1, "Melee", "Carnitree\\CarnitreeIdleEnemy.png",
{
    "Carnitree\\CarnitreeEnemy1.png", "Carnitree\\CarnitreeEnemy2.png", "Carnitree\\CarnitreeEnemy3.png",
    "Carnitree\\CarnitreeEnemy4.png", "Carnitree\\CarnitreeEnemy5.png", "Carnitree\\CarnitreeEnemy6.png",
    "Carnitree\\CarnitreeEnemy7.png", "Carnitree\\CarnitreeEnemy8.png"
},
{"Carnitree\\CarnitreeAttackEnemy1.png", "Carnitree\\CarnitreeAttackEnemy2.png"}, 0, 7, 100, 100, 8,
550, 30, 2, 65, 15);

const Monster Predator ("Predator", 2, "Melee", "Carnitree\\CarnitreeIdleEnemy.png",
{
    "Carnitree\\CarnitreeEnemy1.png", "Carnitree\\CarnitreeEnemy2.png", "Carnitree\\CarnitreeEnemy3.png",
    "Carnitree\\CarnitreeEnemy4.png", "Carnitree\\CarnitreeEnemy5.png", "Carnitree\\CarnitreeEnemy6.png",
    "Carnitree\\CarnitreeEnemy7.png", "Carnitree\\CarnitreeEnemy8.png"
},
{"Carnitree\\CarnitreeAttackEnemy1.png", "Carnitree\\CarnitreeAttackEnemy2.png"}, 0, 7, 100, 100, 8,
600, 30, 3, 65, 15);

const Monster Climber("Climber", 4, "Melee", "Crops\\CropsIdleEnemy.png",
{
    "Crops\\CropsEnemy1.png", "Crops\\CropsEnemy2.png", "Crops\\CropsEnemy3.png",
    "Crops\\CropsEnemy4.png", "Crops\\CropsEnemy5.png", "Crops\\CropsEnemy6.png",
    "Crops\\CropsEnemy7.png", "Crops\\CropsEnemy8.png"
},
{"Crops\\CropsAttackEnemy1.png", "Crops\\CropsAttackEnemy2.png"}, 0, 6, 110, 110, 7,
1000, 50, 5, 70, 25);

const Monster FireBomb ("FireBomb", 2, "Melee", "Magma\\MagmaIdleEnemy.png",
{
    "Magma\\MagmaEnemy1.png", "Magma\\MagmaEnemy2.png", "Magma\\MagmaEnemy3.png",
    "Magma\\MagmaEnemy4.png", "Magma\\MagmaEnemy5.png", "Magma\\MagmaEnemy6.png",
    "Magma\\MagmaEnemy7.png", "Magma\\MagmaEnemy8.png"
},
{"Magma\\MagmaAttackEnemy1.png", "Magma\\MagmaAttackEnemy2.png"}, 0, 8, 110, 110, 8,
900, 40, 6, 65, 30);

const Monster Volcano ("Volcano", 10, "Melee", "Magma\\MagmaIdleEnemy.png",
{
    "Magma\\MagmaEnemy1.png", "Magma\\MagmaEnemy2.png", "Magma\\MagmaEnemy3.png",
    "Magma\\MagmaEnemy4.png", "Magma\\MagmaEnemy5.png", "Magma\\MagmaEnemy6.png",
    "Magma\\MagmaEnemy7.png", "Magma\\MagmaEnemy8.png"
},
{"Magma\\MagmaAttackEnemy1.png", "Magma\\MagmaAttackEnemy2.png"}, 0, 8, 140, 140, 10,
2250, 90, 17, 75, 40);

const Monster LandLord("LandLord", 10, "Melee", "Crops\\CropsIdleEnemy.png",
{
    "Crops\\CropsEnemy1.png", "Crops\\CropsEnemy2.png", "Crops\\CropsEnemy3.png",
    "Crops\\CropsEnemy4.png", "Crops\\CropsEnemy5.png", "Crops\\CropsEnemy6.png",
    "Crops\\CropsEnemy7.png", "Crops\\CropsEnemy8.png"
},
{"Crops\\CropsAttackEnemy1.png", "Crops\\CropsAttackEnemy2.png"}, 0, 6, 120, 120, 7,
5000, 210, 30, 95, 90);
