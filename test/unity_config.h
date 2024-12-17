#ifndef UNITY_CONFIG_H
#define UNITY_CONFIG_H

// Custom output functions for Unity
#ifndef UNITY_OUTPUT_START
    #define UNITY_OUTPUT_START()    unityOutputStart()
#endif

#ifndef UNITY_OUTPUT_CHAR
    #define UNITY_OUTPUT_CHAR(c)    unityOutputChar(c)
#endif

#ifndef UNITY_OUTPUT_FLUSH
    #define UNITY_OUTPUT_FLUSH()    unityOutputFlush()
#endif

#ifndef UNITY_OUTPUT_COMPLETE
    #define UNITY_OUTPUT_COMPLETE() unityOutputComplete()
#endif

#endif // UNITY_CONFIG_H

