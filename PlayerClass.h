
class Entity{

  int hp = 100, atk = 20, def = 10;
  std::string name;
  bool alive = true;

protected:
  void setName(std::string n){
    name = n;
  }
  void damage(int damage){
    hp -= (damage-def);
  }
  void die(){
    std::cout << name <<  " is D Y I N G" << '\n' << '\n';
    this->alive = false;
  }

public:
  void printStats(){
    printName();
    printHp();
    printAtk();
    printDef();
    std::cout << '\n';
  }
  void printName(){
    std::cout<< "Name: " << name << std::endl;
  }
  void printHp(){
    std::cout<< "HP: " << hp << std::endl;
  }
  void printAtk(){
    std::cout<< "ATK: " << atk << std::endl;
  }
  void printDef(){
    std::cout<< "DEF: " << def << std::endl;
  }
  std::string retName(){

    return name;
  }
  bool isAlive(){
    return alive;
  }
  int atkVal(){
    return atk;
  }
  int hpVal(){
    return hp;
  }
  void attack(Entity& attackee, int extraDamage = 0){

    if(alive){
      std::cout << this->retName() << " attacking " << attackee.retName() << std::endl << std::endl;
      attackee.damage(this->atkVal() + extraDamage);
      if(attackee.hpVal()<=0){
        attackee.die();
      }
    } else{
      std::cout << this->retName() << ", the dead cannot attack. : )" << '\n';
    }

  }


};

class Enemy: public Entity {

public:
  Enemy(){
    this->setName("enemy");
  }
  void makeNoise(){
    std::cout << "*grr*" << '\n';
  }

};

class Player: public Entity {

public:
  Player(){
    this->setName("player");
  }
  Player(std::string characterName){
    //name= characterName;
    this->setName(characterName);
  }
  void yellName(){
    std::string s = retName();
    std::cout << "Hello, I'm " << s <<std::endl<<std::endl;
  }
  void whack(Entity& attackee){
    this->attack(attackee);
  }
  void combo(Entity& attackee){

    std::cout << "combo!" << '\n';
    this->attack(attackee,25);
  }

};
