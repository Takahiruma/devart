import ddf.minim.*;
import ddf.minim.analysis.*;

Minim minim;
AudioInput in;
FFT fftLin;
GestionOnde GOnde;
PImage sprite;
boolean affiche = false;

void setup()
{
  size(800, 600, P3D);
  sprite = loadImage("sprite.png");

  minim = new Minim(this);
  in = minim.getLineIn(Minim.MONO, 1024);

  fftLin = new FFT( in.bufferSize(), in.sampleRate() );
  fftLin.linAverages( 30 );

  println("fréquence d'échantillonnage : " + in.sampleRate() + " Hz");
  println("Taille du buffer : " + in.bufferSize());
  println("Taille de la FFT : " + fftLin.specSize());
  
  GOnde = new GestionOnde(1000);
}

void draw()
{
  background(0);
  stroke(255);

  fftLin.forward(in.mix);

  for (int i = 0; i < in.bufferSize() - 1; i++)
  {
  //  line( i, 100 + in.left.get(i)*50, i+1, 100 + in.left.get(i+1)*50 );
  }

  stroke(255);
  float max = 0;
  int freq_max = 0;
  for (int i = 0; i < fftLin.specSize(); i++)
  {
    float val = fftLin.getBand(i);
    //line(i, 380, i, 380 - val*30);
    if ( val > max && i>2 )
    {
      max = val;
      freq_max = i;
    }
  }

  //PARCOURIR TABLAL GESTION DES ONDES
  //AFFICHER
  GOnde.update();
  //stroke(255, 255, 0);
  //line(freq_max, 380, freq_max, 380 - max*30);
  int x = int(random(0,width));
  int y = int(random(0,height));
  //ellipse(x,y,20,20);
  float freq = (0.5*freq_max/(float)fftLin.specSize())*in.sampleRate();
  if(max>1.0f)
  {
    GOnde.setEmitter(x,y,freq);
  }
  GOnde.display();
  
  
  if(affiche){
    fill(255);
    textSize( 32 );
    text((int)(freq) + " Hz", width/2.5, height/2);
    text("val = " + nf(max, 0, 2), width/2.5, height/2+30);
  }
  
  //DIVISION DU TERRAIN
  PVector middle = new PVector(width/2, height/2);
  
  //PARCOURS DES ONDES POUR TEST COLLISION
  for(int i = 0; i < GOnde.ondes.size(); ++i)
  {
    if(!GOnde.ondes.get(i).isDead() && GOnde.ondes.get(i).isInScreen()) {
      for(int j = i+1; j < GOnde.ondes.size();j++){
        if(!GOnde.ondes.get(j).isDead() && GOnde.ondes.get(j).isInScreen()) {
          if((GOnde.ondes.get(i).position.y > middle.y && GOnde.ondes.get(j).position.y > middle.y) ||
          (GOnde.ondes.get(i).position.y < middle.y && GOnde.ondes.get(j).position.y < middle.y) ||
          (middle.y < GOnde.ondes.get(i).position.y && GOnde.ondes.get(i).position.y < middle.y + GOnde.ondes.get(i).radius) ||
          (middle.y < GOnde.ondes.get(j).position.y && GOnde.ondes.get(j).position.y < middle.y + GOnde.ondes.get(j).radius)
          ){
            GOnde.ondes.get(i).checkCollisionOnde(GOnde.ondes.get(j));
          }
        }
      }
    }      
  }
}


void keyPressed()
{
   if (key == 'a' || key == 'A') {
      if(affiche)
        affiche = false;
      else
        affiche = true;
   }
}
