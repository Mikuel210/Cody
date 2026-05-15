
class Program {
  public:
    static void go() {
      cemento();
      bloques();
      herramientas();
    }

  private:
    static void cemento() {
      /*
      Cody::homeAsync()->await();
      Cody::moveToolheadAsync(100, 25)->await();
      Cody::moveAsync(0, 1'000, 50);
      */

      /*
      Cody::addPathPoint(0, 700);
      Cody::addPathPoint(1700, 700);
      Cody::addPathPoint(1700, 0);
      Cody::addPathPoint(0, 0);
      Cody::followPathAsync(50);
      */

      Cody::moveMillAsync(360);
    }

    static void bloques() {

    }

    static void herramientas() {

    }
};
