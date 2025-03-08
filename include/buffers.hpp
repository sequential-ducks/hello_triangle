#include <memory>

/**
 * @class Buffers.
 * @brief Base class for datastructures in GPU's memory enabling data to be sent 
 *        from cpu to gpu in batches. Specific buffers inherit from this class.
 */
class Buffers{
    public:
        /**
        * @subsection Constructors
        */
        /**
        * @subsection Destructors
        */
        /**
        * @subsection Public Member Functions
        */
        
        /**
        * @subsection Getters
        */
        /**
        * @subsection Setters
        */
        void generateBuffer(const unsigned int &howMany);
    
    protected:
        /**
         * @var Buffers::VBO_id
         * @brief ID of a buffer. Default null.
         */
        std::unique_ptr<unsigned int> buffer_id{ nullptr };
    
    
    };
    
    /**
     * @class VBO 
     * @brief Vertex Buffer Object, public inheritance from Buffers.
     */
    class VBO : public Buffers{
    public:
        /**
        * @subsection Constructors
        */
    
        /**
        * @subsection Destructors
        */
        /**
        * @subsection Public Member Functions
        */
    
        /**
        * @subsection Getters
        */
        /**
        * @subsection Setters
        */
        /**
         * @brief Initializes an object that holds space for vertices on the 
         *        GPU's memory.
         * @note Assigns an ID for the Vertex Buffer Object.
         */
        VBO();
};
    