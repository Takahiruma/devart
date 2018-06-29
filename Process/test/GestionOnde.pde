class GestionOnde {
  ArrayList<onde> ondes;

  PShape ondeShape;

  GestionOnde(int n) {
    ondes = new ArrayList<onde>();
    ondeShape = createShape(PShape.GROUP);

    for (int i = 0; i < n; i++) {
      onde p = new onde();
      ondes.add(p);
      ondeShape.addChild(p.getShape());
    }
  }

  void update() {
    for (onde p : ondes) {
      p.update();
    }
  }

  void setEmitter(float x, float y, float freq) {
    float semiTone = 12*(log(freq/261.63)/log(2));
    float floating = semiTone - int(semiTone);
    int intSemiTone = floating > 0.5 ? int(semiTone)+1 : int(semiTone);
    int normalizedSemiTones = intSemiTone % 12;
    int octav = 3 + intSemiTone / 12;
    if(normalizedSemiTones < 0)
    {
      normalizedSemiTones += 12;
      octav -= 1;
    }
    float bright = (float)255*(((float)octav+1.0f)/8.0f);
    //println(bright);
    color c = color(30*normalizedSemiTones,255,bright);
    
    int index = 0;
    boolean isOver = false;
    while (index < ondes.size() && !isOver)
    {
      if (ondes.get(index).isDead()) {
        ondes.get(index).rebirth(x, y, c);
        isOver = true;
      }
     index++; 
    }
  }

  void display() {

    shape(ondeShape);
  }
}
