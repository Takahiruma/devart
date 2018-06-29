class onde {

  PVector velocity;
  float lifespan = 255;
  
  PShape part;
  float partSize;
  color spriteColor;


  onde() {
    partSize = random(10,60);  //régler taile entre min et max (avec une limite)
    spriteColor = color(25,244,244);
    part = createShape();
    
    part.beginShape(QUAD);
    part.noStroke();
    part.texture(sprite);
    part.normal(0, 0, 1);
    part.vertex(-partSize/2, -partSize/2, 0, 0);
    part.vertex(+partSize/2, -partSize/2, sprite.width, 0);
    part.vertex(+partSize/2, +partSize/2, sprite.width, sprite.height);
    part.vertex(-partSize/2, +partSize/2, 0, sprite.height);
    part.endShape();
    
    rebirth(width/2,height/2,spriteColor);
    lifespan = random(255);
  }

  PShape getShape() {
    return part;
  }
  
  void rebirth(float x, float y, color c) {
    spriteColor = c;
    float a = random(TWO_PI);
    float speed = random(0.5,4);
    velocity = new PVector(cos(a), sin(a));
    velocity.mult(speed);
    lifespan = 255;   
    part.resetMatrix();
    part.translate(x, y); 
  }
  
  boolean isDead() {
    if (lifespan < 0) {
     return true;
    } else {
     return false;
    } 
  }
  
  void colorize(float alpha) {
    colorMode(HSB,360,255,255,1.0);
    part.setTint(color(hue(spriteColor),saturation(spriteColor),brightness(spriteColor),alpha));
  }
  

  public void update() {
    lifespan = lifespan - 1;
   
    colorize(lifespan/255);
    part.translate(velocity.x, velocity.y);
  }
}
