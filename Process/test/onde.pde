class onde {

  PVector position;
  PVector velocity;
  float lifespan = 255;
  float radius, m;
  
  PShape part;
  float partSize;
  color spriteColor;


//CONSTRUCTEUR
  onde(float _radius) {
    partSize = random(10,60);  //régler taile entre min et max (avec une limite)
    spriteColor = color(25,244,244);
    part = createShape();
    radius = _radius;
    m = radius *.1;
    
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

//RECUPERER LA FORME
  PShape getShape() {
    return part;
  }
  
//RENAISSANCE 
  void rebirth(float x, float y, color c) {
    spriteColor = c;
    float a = random(TWO_PI);
    float speed = random(0.5,4);
    velocity = new PVector(cos(a), sin(a));
    velocity.mult(speed);
    lifespan = 255;   
    position = new PVector(x,y);
    part.resetMatrix();
    part.translate(x, y); 
  }
  
//MEDECIN LEGISTE
  boolean isDead() {
    return lifespan < 0; 
  }
  
  boolean isInScreen()
  {
    return !(position.x > width) || !(position.y > height) || !(position.x < 0) || !(position.y < 0);
  }
  
//MODIFICATION DE LA COULEUR
  void colorize(float alpha) {
    colorMode(HSB,360,255,255,1.0);
    part.setTint(color(hue(spriteColor),saturation(spriteColor),brightness(spriteColor),alpha));
  }
  

//TEST DE COLLISION
void checkCollisionOnde(onde other)
{
  //Distance entre les ondes
  PVector distanceBetween = PVector.sub(other.position, position);
  
  //Magnitude du vecteur séparant les ondes
  float distanceVectMag = distanceBetween.mag();
  
  //Distance minimum avant la collision
  float minDistance = radius + other.radius;
  
  if(distanceVectMag < minDistance) {
    float distanceCorrection = (minDistance-distanceVectMag)/2.0;
    PVector d = distanceBetween.copy();
    PVector correctionVector = d.normalize().mult(distanceCorrection);
    other.position.add(correctionVector);
    position.sub(correctionVector);
    
    //angle de distanceBetween
    float theta = distanceBetween.heading();
    //precalculation des valeurs trigo
    float sine   = sin(theta);
    float cosine = cos(theta);
    
    /*bTemp contient temporairement la position des ondes*/
    PVector[] bTemp = {
      new PVector(), new PVector()
    };
    
    bTemp[1].x = cosine * distanceBetween.x + sine * distanceBetween.y;
    bTemp[1].y = sine * distanceBetween.y - sine * distanceBetween.x;
    
    //changement des positions temporaires
    PVector[] vTemp = {
      new PVector(), new PVector()
    };
    
    vTemp[0].x = cosine * velocity.x + sine * velocity.y;
    vTemp[0].y = cosine * velocity.y- sine * velocity.x;
    vTemp[1].x = cosine * other.velocity.x + sine * other.velocity.y;
    vTemp[1].y  = cosine * other.velocity.y - sine * other.velocity.x;

      /* Now that velocities are rotated, you can use 1D
       conservation of momentum equations to calculate 
       the final velocity along the x-axis. */
      PVector[] vFinal = {  
        new PVector(), new PVector()
      };

      // final rotated velocity for b[0]
      vFinal[0].x = ((m - other.m) * vTemp[0].x + 2 * other.m * vTemp[1].x) / (m + other.m);
      vFinal[0].y = vTemp[0].y;

      // final rotated velocity for b[0]
      vFinal[1].x = ((other.m - m) * vTemp[1].x + 2 * m * vTemp[0].x) / (m + other.m);
      vFinal[1].y = vTemp[1].y;

      // hack to avoid clumping
      bTemp[0].x += vFinal[0].x;
      bTemp[1].x += vFinal[1].x;

      /* Rotate ball positions and velocities back
       Reverse signs in trig expressions to rotate 
       in the opposite direction */
      // rotate balls
      PVector[] bFinal = { 
        new PVector(), new PVector()
      };

      bFinal[0].x = cosine * bTemp[0].x - sine * bTemp[0].y;
      bFinal[0].y = cosine * bTemp[0].y + sine * bTemp[0].x;
      bFinal[1].x = cosine * bTemp[1].x - sine * bTemp[1].y;
      bFinal[1].y = cosine * bTemp[1].y + sine * bTemp[1].x;

      // update balls to screen position
      other.position.x = position.x + bFinal[1].x;
      other.position.y = position.y + bFinal[1].y;

      position.add(bFinal[0]);

      // update velocities
      velocity.x = cosine * vFinal[0].x - sine * vFinal[0].y;
      velocity.y = cosine * vFinal[0].y + sine * vFinal[0].x;
      other.velocity.x = cosine * vFinal[1].x - sine * vFinal[1].y;
      other.velocity.y = cosine * vFinal[1].y + sine * vFinal[1].x;
    }
}
  

  public void update() {
    lifespan = lifespan - 1;
    position.add(velocity.x, velocity.y);
   
    colorize(lifespan/255);
    part.translate(velocity.x, velocity.y);
  }
}
