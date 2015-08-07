#ifndef TECS_VERTEXINFO
#define TECS_VERTEXINFO

namespace ecs
{
   static GLfloat cubeVertexDataN[] = {
        //  X     Y     Z       U     V          Normal
        // bottom
        -1.0f,-1.0f,-1.0f,   0.0f, 0.0f,   0.0f, -1.0f, 0.0f,
         1.0f,-1.0f,-1.0f,   1.0f, 0.0f,   0.0f, -1.0f, 0.0f,
        -1.0f,-1.0f, 1.0f,   0.0f, 1.0f,   0.0f, -1.0f, 0.0f,
         1.0f,-1.0f,-1.0f,   1.0f, 0.0f,   0.0f, -1.0f, 0.0f,
         1.0f,-1.0f, 1.0f,   1.0f, 1.0f,   0.0f, -1.0f, 0.0f,
        -1.0f,-1.0f, 1.0f,   0.0f, 1.0f,   0.0f, -1.0f, 0.0f,

        // top
        -1.0f, 1.0f,-1.0f,   0.0f, 0.0f,   0.0f, 1.0f, 0.0f,
        -1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   0.0f, 1.0f, 0.0f,
         1.0f, 1.0f,-1.0f,   1.0f, 0.0f,   0.0f, 1.0f, 0.0f,
         1.0f, 1.0f,-1.0f,   1.0f, 0.0f,   0.0f, 1.0f, 0.0f,
        -1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   0.0f, 1.0f, 0.0f,
         1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   0.0f, 1.0f, 0.0f,

        // front
        -1.0f,-1.0f, 1.0f,   1.0f, 0.0f,   0.0f, 0.0f, 1.0f,
         1.0f,-1.0f, 1.0f,   0.0f, 0.0f,   0.0f, 0.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   0.0f, 0.0f, 1.0f,
         1.0f,-1.0f, 1.0f,   0.0f, 0.0f,   0.0f, 0.0f, 1.0f,
         1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   0.0f, 0.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   0.0f, 0.0f, 1.0f,

        // back
        -1.0f,-1.0f,-1.0f,   0.0f, 0.0f,   0.0f, 0.0f, -1.0f,
        -1.0f, 1.0f,-1.0f,   0.0f, 1.0f,   0.0f, 0.0f, -1.0f,
         1.0f,-1.0f,-1.0f,   1.0f, 0.0f,   0.0f, 0.0f, -1.0f,
         1.0f,-1.0f,-1.0f,   1.0f, 0.0f,   0.0f, 0.0f, -1.0f,
        -1.0f, 1.0f,-1.0f,   0.0f, 1.0f,   0.0f, 0.0f, -1.0f,
         1.0f, 1.0f,-1.0f,   1.0f, 1.0f,   0.0f, 0.0f, -1.0f,

        // left
        -1.0f,-1.0f, 1.0f,   0.0f, 1.0f,   -1.0f, 0.0f, 0.0f,
        -1.0f, 1.0f,-1.0f,   1.0f, 0.0f,   -1.0f, 0.0f, 0.0f,
        -1.0f,-1.0f,-1.0f,   0.0f, 0.0f,   -1.0f, 0.0f, 0.0f,
        -1.0f,-1.0f, 1.0f,   0.0f, 1.0f,   -1.0f, 0.0f, 0.0f,
        -1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   -1.0f, 0.0f, 0.0f,
        -1.0f, 1.0f,-1.0f,   1.0f, 0.0f,   -1.0f, 0.0f, 0.0f,

        // right
         1.0f,-1.0f, 1.0f,   1.0f, 1.0f,   1.0f, 0.0f, 0.0f,
         1.0f,-1.0f,-1.0f,   1.0f, 0.0f,   1.0f, 0.0f, 0.0f,
         1.0f, 1.0f,-1.0f,   0.0f, 0.0f,   1.0f, 0.0f, 0.0f,
         1.0f,-1.0f, 1.0f,   1.0f, 1.0f,   1.0f, 0.0f, 0.0f,
         1.0f, 1.0f,-1.0f,   0.0f, 0.0f,   1.0f, 0.0f, 0.0f,
         1.0f, 1.0f, 1.0f,   0.0f, 1.0f,   1.0f, 0.0f, 0.0f
    };

  static GLfloat cubeVertexData[] = {
          //  X     Y     Z       U     V
          // bottom
          -1.0f,-1.0f,-1.0f,   0.0f, 0.0f,
           1.0f,-1.0f,-1.0f,   1.0f, 0.0f,
          -1.0f,-1.0f, 1.0f,   0.0f, 1.0f,
           1.0f,-1.0f,-1.0f,   1.0f, 0.0f,
           1.0f,-1.0f, 1.0f,   1.0f, 1.0f,
          -1.0f,-1.0f, 1.0f,   0.0f, 1.0f,

          // top
          -1.0f, 1.0f,-1.0f,   0.0f, 0.0f,
          -1.0f, 1.0f, 1.0f,   0.0f, 1.0f,
           1.0f, 1.0f,-1.0f,   1.0f, 0.0f,
           1.0f, 1.0f,-1.0f,   1.0f, 0.0f,
          -1.0f, 1.0f, 1.0f,   0.0f, 1.0f,
           1.0f, 1.0f, 1.0f,   1.0f, 1.0f,

          // front
          -1.0f,-1.0f, 1.0f,   1.0f, 0.0f,
           1.0f,-1.0f, 1.0f,   0.0f, 0.0f,
          -1.0f, 1.0f, 1.0f,   1.0f, 1.0f,
           1.0f,-1.0f, 1.0f,   0.0f, 0.0f,
           1.0f, 1.0f, 1.0f,   0.0f, 1.0f,
          -1.0f, 1.0f, 1.0f,   1.0f, 1.0f,

          // back
          -1.0f,-1.0f,-1.0f,   0.0f, 0.0f,
          -1.0f, 1.0f,-1.0f,   0.0f, 1.0f,
           1.0f,-1.0f,-1.0f,   1.0f, 0.0f,
           1.0f,-1.0f,-1.0f,   1.0f, 0.0f,
          -1.0f, 1.0f,-1.0f,   0.0f, 1.0f,
           1.0f, 1.0f,-1.0f,   1.0f, 1.0f,

          // left
          -1.0f,-1.0f, 1.0f,   0.0f, 1.0f,
          -1.0f, 1.0f,-1.0f,   1.0f, 0.0f,
          -1.0f,-1.0f,-1.0f,   0.0f, 0.0f,
          -1.0f,-1.0f, 1.0f,   0.0f, 1.0f,
          -1.0f, 1.0f, 1.0f,   1.0f, 1.0f,
          -1.0f, 1.0f,-1.0f,   1.0f, 0.0f,

          // right
           1.0f,-1.0f, 1.0f,   1.0f, 1.0f,
           1.0f,-1.0f,-1.0f,   1.0f, 0.0f,
           1.0f, 1.0f,-1.0f,   0.0f, 0.0f,
           1.0f,-1.0f, 1.0f,   1.0f, 1.0f,
           1.0f, 1.0f,-1.0f,   0.0f, 0.0f,
           1.0f, 1.0f, 1.0f,   0.0f, 1.0f
      };

  static GLfloat pyramidVertexData[] = {

  	//  X     Y     Z       U     V
      // base
        -1.0f,-1.0f,-1.0f,   0.0f, 0.0f,
         1.0f,-1.0f,-1.0f,   1.0f, 0.0f,
        -1.0f,-1.0f, 1.0f,   0.0f, 1.0f,
         1.0f,-1.0f,-1.0f,   1.0f, 0.0f,
         1.0f,-1.0f, 1.0f,   1.0f, 1.0f,
        -1.0f,-1.0f, 1.0f,   0.0f, 1.0f,

  	//side north
  	  -1.0f,-1.0f, 1.0f,   1.0f, 0.0f,
  	   1.0f,-1.0f, 1.0f,   0.0f, 0.0f,
  	   0.0f, 1.0f, 0.0f,   0.5f, 1.0f, //top

  	//side east
  	   1.0f,-1.0f, 1.0f,   1.0f, 0.0f,
  	   0.0f, 1.0f, 0.0f,   0.5f, 1.0f, //top
  	   1.0f,-1.0f,-1.0f,   0.0f, 0.0f,

  	//side west
  	   0.0f, 1.0f, 0.0f,   0.5f, 1.0f, //top
  	  -1.0f,-1.0f, 1.0f,   0.0f, 0.0f,
  	  -1.0f,-1.0f,-1.0f,   1.0f, 0.0f,

  	//side south
  	   0.0f, 1.0f, 0.0f,   0.5f, 1.0f, //top
  	  -1.0f,-1.0f,-1.0f,   0.0f, 0.0f,
  	   1.0f,-1.0f,-1.0f,   1.0f, 0.0f

  };
}

#endif
/* TECS_VERTEXINFO */