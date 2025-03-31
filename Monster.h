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
500, 30, 5, 65, 20,
40, 5, 2, 2, 2, 100);

const Monster Eater ("Eater", 1, "Melee", "Carnitree\\CarnitreeIdle.png",
{
    "Carnitree\\Carnitree1.png", "Carnitree\\Carnitree2.png", "Carnitree\\Carnitree3.png",
    "Carnitree\\Carnitree4.png", "Carnitree\\Carnitree5.png", "Carnitree\\Carnitree6.png",
    "Carnitree\\Carnitree7.png", "Carnitree\\Carnitree8.png"
},
{"Carnitree\\CarnitreeAttack1.png", "Carnitree\\CarnitreeAttack2.png"}, 0, 7, 100, 100, 8,
450, 40, 3, 65, 20,
30, 6, 1, 1, 4, 100
                    );

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

const Monster Hungtree ("Hungtree", 1, "Melee", "Carnitree\\CarnitreeIdleEnemy.png",
{
    "Carnitree\\CarnitreeEnemy1.png", "Carnitree\\CarnitreeEnemy2.png", "Carnitree\\CarnitreeEnemy3.png",
    "Carnitree\\CarnitreeEnemy4.png", "Carnitree\\CarnitreeEnemy5.png", "Carnitree\\CarnitreeEnemy6.png",
    "Carnitree\\CarnitreeEnemy7.png", "Carnitree\\CarnitreeEnemy8.png"
},
{"Carnitree\\CarnitreeAttackEnemy1.png", "Carnitree\\CarnitreeAttackEnemy2.png"}, 0, 7, 100, 100, 8,
250, 25, 2, 65, 15);

