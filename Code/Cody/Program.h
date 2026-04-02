
class Program {
  public:
    static void go() {
      Cody::addPathPoint(0, 5'000);
      Cody::addPathPoint(5'000, 5'000);
      Cody::addPathPoint(5'000, 10'000);
      Cody::addPathPoint(0, 10'000);
      Cody::addPathPoint(0, 15'000);
      Cody::followPathAsync(1'000);

      
    }    
};