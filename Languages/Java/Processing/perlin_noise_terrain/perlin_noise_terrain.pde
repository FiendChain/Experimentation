final float scale = 12;
final float granularity = 0.1;
final float xRotation = PI/4;

final PVector resolution = new PVector(1920, 1000);
final PVector terrainSize = new PVector(
  (int)(resolution.x/scale),
  (int)(resolution.y/scale)
);

final float yOffsetRender = resolution.y*(1-cos(xRotation))/2;

PVector position = new PVector(0, 0);

float[][] terrain;

void settings() {
  size((int)resolution.x, (int)resolution.y, P3D);
}

void setup() {
  terrain = new float[(int)terrainSize.x][(int)terrainSize.y];
  init_terrain();
}

int overrideY = (int)(terrainSize.y-1);  // row to override

void init_terrain() {
  float yPos = position.y;
  for(int y = 0; y < terrainSize.y; y++) {  
    float xPos = position.x;
    for(int x = 0; x < terrainSize.x; x++) {
      terrain[x][y] = map(noise(xPos, yPos), 0, 1, -200, 200);
      xPos += granularity;   
    }
    yPos += granularity;  
  }
  position.y = yPos;
}

void update() {
  // override current row
  overrideY -= 1;
  if(overrideY < 0) overrideY = (int)(terrainSize.y-1);  // prevent overflow
  float xPos = position.x;
  for(int x = 0; x < terrainSize.x; x++) {
    terrain[x][overrideY] = map(noise(xPos, position.y), 0, 1, -100, 100);
    xPos += granularity;
  }
  position.y += granularity;
}

void renderTerrain() {
  int currentY = overrideY;
  int currentYNext;
  for(int y = 0; y < terrainSize.y-1; y++) {
    if(currentY >= terrainSize.y) currentY = 0;
    currentYNext = (currentY >= terrainSize.y-1) ? 0 : currentY+1;
    beginShape(TRIANGLE_STRIP);
    for(int x = 0; x < terrainSize.x; x++) {
      vertex(x*scale, y*scale, terrain[x][currentY]);
      vertex(x*scale, (y+1)*scale, terrain[x][currentYNext]);
    }
    currentY += 1;
    endShape();
  }
}

void render() { //<>//
  background(0);
  stroke(255);
  noFill();
  translate(0, yOffsetRender);
  rotateX(xRotation);
  renderTerrain();
}

void draw() {
  update();
  render(); 
}
