#ifndef  EDGE_CU
#define EDGE_CU

#include "Util.h"

template<typename DATA_TYPE,typename COUNT_TYPE>
class Edge_CU{
public:

    Edge_CU(uint32_t _MEMORY){
        LENGTH = _MEMORY / sizeof(COUNT_TYPE) / HASH_NUM;
        positions = new COUNT_TYPE [HASH_NUM];
        sketch = new COUNT_TYPE* [HASH_NUM];
        for(uint32_t i = 0;i < HASH_NUM; ++i){
            sketch[i] = new COUNT_TYPE[LENGTH];
            memset(sketch[i], 0, sizeof(COUNT_TYPE) * LENGTH);
        }
    }

    ~Edge_CU(){
        for(uint32_t i = 0;i < HASH_NUM;++i)
            delete [] sketch[i];
        delete [] sketch;
    }

    void Insert(const DATA_TYPE item, uint32_t f) {
	uint32_t minval = 1 << 31;
        for(uint32_t i = 0; i < HASH_NUM; ++i) {
            uint32_t position = hash(item, i) % LENGTH;
	    positions[i] = position;
	    minval = (minval < sketch[i][position] ? minval : sketch[i][position] );
        }
	uint32_t temp = minval + f;
       for(uint32_t i = 0; i < HASH_NUM; ++i) {
	   sketch[i][positions[i]] = (sketch[i][positions[i]] >temp ? sketch[i][positions[i]] : temp);
       }
    }
    COUNT_TYPE Query(const DATA_TYPE item){
        //std::vector<COUNT_TYPE> result(HASH_NUM);
        uint64_t res = 1  << 31;
        for(uint32_t i = 0; i < HASH_NUM; ++i) {
            uint32_t position = hash(item, i) % LENGTH;
            //uint32_t polar = hash(item, i + HASH_NUM) & 1;
            res =(res < sketch[i][position] ? res : sketch[i][position]);
            //result[i] = sketch[i][position] * delta[polar];
        }
        return res;
    }

private:
    const int32_t delta[2] = {+1, -1};

    uint32_t LENGTH;
    const uint32_t HASH_NUM = 3;
    uint32_t* positions;
    COUNT_TYPE** sketch;
};

#endif
