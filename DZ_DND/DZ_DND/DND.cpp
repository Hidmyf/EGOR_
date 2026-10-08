#include <iostream> 
#include<vector>
using namespace std;
//ключевые понятия (принципы) ООП:
//1) наследование
//2) полиморфизм
//3) абстракция
//4) инкапсуляция (геттер и сеттер)
//public - публичный (доступен в основной программе, в классе наследника и в основном потоке программы))
//protected - защищеннный (можно изменять в исходном классе и в классе наследника)
//private - приватный (доступен только в исходном классе)
//private - НЕ НАСЛЕДУЕТСЯ
class NPC
{
protected:
    string name{ "npc" };
    unsigned int damage{ 2 };
    unsigned int health{ 5 };
    short lvl = 1;
    unsigned int armor = 2;
private:

public:
    bool isEnemy = true;
    unsigned int GetDamage() { return damage; };
    unsigned int GetHealth() { return health; }; //геттер
    void SetHealth(unsigned int health) { this->health = health; }; //сеттер

    virtual void GetInfo()
    {
        cout << "имя: " << name << endl;
        cout << "здоровье: " << health << endl;
        cout << "урон: " << damage << endl;
        cout << "уровень: " << lvl << endl;
        cout << "броня: " << armor << endl;
    };
    //создать NPC нельзя, поэтому он виртуальный.
    virtual void Create() { }; //хотя бы 1 метод виртуальный, значитвесь класс виртуальный
    void LvlUp()
    {
        cout << name << " получил новый уровень" << endl;
        lvl++;
        Relaculate();
    }
    void Relaculate() //кастомизировать для война и волшебника зависимости от инт/силы
    {
        damage += (1 + lvl * 0.1);
        health += (1 + lvl * 0.1);
        armor += (1 + lvl * 0.1);
    }

    friend void TakeDamage(NPC* npc, unsigned int damage);

    virtual ~NPC() = default;

    //NPC()
    //{
    //    cout << "Вы создали NPC";
    //    name = "npc";
    //    damage = 2;
    //    health = 5;
    //    lvl = 1;
    //    armor = 2;
    //}
    //~NPC()
    //{
    //    cout << "NPC уничтожен";
    //}
};

struct Weapon
{
    string name{ "weapon" };
    unsigned int damage{ 1 };
};

class Warrior : virtual public NPC
{
protected:
    short strength{ 21 };
    vector<Weapon> weapons;
public:
    //конструктор по умолчанию
    Warrior()
    {
        //cout << "конструктор война" << endl;
        damage = 20;
        health = 30;
        armor = 15;
        //Create();
    }
    //кастомный конструктор
    Warrior(string name, unsigned int lvl)
    {
        damage = 20;
        health = 30;
        armor = 15;
        this->name = name; //такой способ задания поля уместен только для сеттер
        for (size_t i = 0; i < lvl; i++)
        {
            LvlUp();
        }
        //this->lvl = lvl; //this - указывает на конкрестный экземпляр класса
    }
    void Create() override
    {
        cout << "Вы создали война\nЗадайте имя игрока\n";
        cin >> name;

        GetInfo();
        GetWeapon();
    };
    void GetInfo()
    {
        NPC::GetInfo();
        cout << "сила: " << strength << endl;
    };

    // Задание 1.1
    void Relaculate()
    {
        damage += (1 + lvl * 0.1) + (strength * 0.5); // прибавка от силы
        health += (1 + lvl * 0.1) + 10;
        armor += (1 + lvl * 0.1) + 5;
    }

    void GetWeapon()
    {
        Weapon weapon;
        weapon.damage = 1;
        weapon.name = "кулаки";
        weapons.push_back(weapon);

        cout << name << " взял в руки оружие " << weapons[0].name << endl;
        cout << " добавка к урону = " << weapons[0].damage << endl;
    };
    ~Warrior() //деструктор (вызывается сам в момент высвобождения памяти экземпляра)
    {
        cout << name << " пал смертью храбрых" << endl;
    }
};

struct Spell
{
    string name{ "spell" };
    unsigned int damage{ 1 };
};

class Wizard : virtual public NPC
{
protected:
    short intellect{ 29 };
    vector<Spell> spells;
public:
    Wizard()//конструктор вызывается в момент создания экземпляра
    {
        //cout << "конструктор волшебник" << endl;
        damage = 27;
        health = 21;
        armor = 10;
        //Create();
    }
    void Create() override
    {
        cout << "Вы создали волшебник\nЗадайте имя игрока\n";
        cin >> name;

        GetInfo();
        LearnSpell();
    };
    void GetInfo() override
    {
        NPC::GetInfo();
        cout << "интеллект: " << intellect << endl;
    };

    // ЗАДАНИЕ 1.2
    void Relaculate()
    {
        damage += (1 + lvl * 0.1) + (intellect * 0.8); // прибавка от интеллекта
        health += (1 + lvl * 0.1) + 3;
        armor += (1 + lvl * 0.1) + 1;
    }

    void LearnSpell()
    {
        Spell spell;
        spell.damage = 2;
        spell.name = "вспышка";
        spells.push_back(spell);

        cout << name << " изучил заклинание " << spells[0].name << endl;
        cout << " добавка к урону = " << spells[0].damage << endl;
    };
    ~Wizard()
    {
        cout << name << " испускает дух" << endl;
    }
};

class Evil : public NPC
{
public:
    Evil()
    {
        name = "Злодей";
        health = 10;
        damage = 5;
        armor = 3;
    }
    Evil(string name) : Evil() //делегирование конструктора (то есть вызовется вначале базовый)
    {
        this->name = name;
    }
    Evil(string name, unsigned int damage) : Evil(name)
    {
        this->damage = damage;
    }
    Evil(string name, unsigned int damage, unsigned int health) : Evil(name, damage)
    {
        this->health = health;
    }
    Evil(string name, unsigned int damage, unsigned int health, unsigned int armor) : Evil(name, damage, health)
    {
        this->armor = armor;
    }

    // Задание 2
    ~Evil()
    {
        cout << name << " не спеша, без суеты  деструктуируется" << endl;
    }
};

//множественное наследование

class Paladin : public Warrior, public Wizard
{
public:
    Paladin()
    {
        intellect = 25;
        strength = 19;
        health = 25;
        damage = 25;
    }

    void Create() override
    {
        //реализуйте это в NPC (храните название класса в квком_то поле)
        cout << "Вы создали паладина\nЗадайте имя игрока\n";
        cin >> name;

        GetInfo();
        LearnSpell();
        GetWeapon();
    };
    void GetInfo() override
    {
        Warrior::GetInfo();
        cout << "интеллект: " << intellect << endl;
    };
    ~Paladin()
    {
        cout << "Отправляется к праотцам" << endl;
    }
};

//дружественные классы
class Player
{
    private:
      unique_ptr<NPC>currentCharacter{nullptr};
    public:
        void Create(unique_ptr<NPC> character)
        {
            currentCharacter = move(character);
            currentCharacter->Create();
        }
        NPC* GetCharacter()
        {
            return currentCharacter.get();
        }

        void LvlUp(unique_ptr<NPC> lvlUp)
        {
            currentLvlUp = move(lvlUp);
            currentLvlUp -> LvlUp();
        }
        NPC* GetLvlUp()
        {
            return currentLvlUp.get();
        }
};
//дружественные к NPC функции - может использовать private поля и методы
void TakeDamage(Npc&, unsigned int damage)
{
    npc.SetHealth(npc.healt - damage);
    cout << "Вам нанесли урон: " << damage << endl;
    cout << "Оставшееся здоровье = " << npc->health << endl;
}

int main()
{
    setlocale(LC_ALL, "Rus");
  
    Player player;

    cout << "Присядь путник у костра и расскажи, кто ты: " << endl;
    cout << "\t1 - воин\n\t2 - волшебник\n\t3 - паладин" << endl;
    short choise = 0;
    cin >> choise;
    switch (choise)
    {
    case 1:
        player.Create(make_unique<Warrior>())
        break;
    case 2:
        player.Create(make_unique<Wizard>())
        break;
    case 3:
        player.Create(make_unique<Paladin>())
        break;
    default:
        cout << "Таких героев еще не было в наших краях.\nПопытай удачу позже"
    }

    TakeDamage(player.GetCharacter(5))

    Paladin paladin;

    Warrior* warrior = new Warrior("друг война", 5); //как только создал новый экземпляр, для него вызвался конструктор
    warrior->GetInfo(); //стрелка работает с указателями

    cout << "Метод публичный, вот значение - " << warrior->GetHealth() << endl;

    delete warrior;
    warrior = nullptr;



    Wizard wizard;

    // Задание 3
    //vector<Evil*> evils;
    //evils.push_back(new Evil());
    //evils.push_back(new Evil("Кабанчик"));
    //evils.push_back(new Evil("Гнолл", 12));
    //evils.push_back(new Evil("Гнолл Дробитель", 15, 20));
    //evils.push_back(new Evil("Дракон", 50, 100, 200));

    // Вывод информации из вектора
    //cout << "\n--- Появление злодеев в игре ---\n";
    //for (size_t i = 0; i < evils.size(); i++)
    //{
    //    evils[i]->GetInfo();
    //    cout << "---------------------\n";
    //}

    //// Очистка выделенной памяти
    //cout << "\n--- Уничтожение злодеев ---\n";
    //for (size_t i = 0; i < evils.size(); i++)
    //{
    //    delete evils[i]; // Безопасно вызывает ~Evil(), так как тип указателя Evil*
    //}
    //evils.clear();

    return 0;
}
//draw io дорисовать 