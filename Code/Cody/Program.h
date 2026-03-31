
class Program {
  public:
    static void go() {
      /*Pursuit::addPoint(0, 5'000);
      Pursuit::addPoint(5'000, 5'000);
      Pursuit::addPoint(5'000, 10'000);
      Pursuit::addPoint(0, 10'000);
      Pursuit::addPoint(0, 15'000);
      Pursuit::followPathAsync(1'000);*/

      Pursuit::moveToolheadAsync(100, 100);
    }
};