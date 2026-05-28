
class Program {
  public:
    static void go() {
      cemento();
      bloques();
      herramientas();
    }

  private:
    static void cemento() {
      Cody::addPathPoint(0, 1000);
      Cody::followPathAsync(50);

      // Cody::moveAsync(0, 500, 50);
    }

    static void bloques() {

    }

    static void herramientas() {

    }
};
