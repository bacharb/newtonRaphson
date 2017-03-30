class Soldier {};
class Monster {};
class SuperMonster {};

class SillySoldier : public  Soldier {};
class SillyMonster : public  Monster {};
class SillySuperMonster : public  SuperMonster {};

class BadSoldier : public  Soldier {};
class BadMonster : public  Monster {};
class BadSuperMonster : public  SuperMonster {};

class AbstractEnemyFactory {
	public:
		virtual Soldier* MakeSoldier() = 0;
		virtual Monster* MakeMonster() = 0;
		virtual SuperMonster* MakeSuperMonster() = 0;
};

class EasyLevelEnemyFactory : public AbstractEnemyFactory {
	public:
		Soldier* MakeSoldier() { return new SillySoldier; }
		Monster* MakeMonster() { return new SillyMonster; }
		SuperMonster* MakeSuperMonster() { return new SillySuperMonster; }
};

class DieHardLevelEnemyFactory : public AbstractEnemyFactory {
	public:
		Soldier* MakeSoldier() { return new BadSoldier; }
		Monster* MakeMonster() { return new BadMonster; }
		SuperMonster* MakeSuperMonster() { return new BadSuperMonster; }
};

main (){

}

