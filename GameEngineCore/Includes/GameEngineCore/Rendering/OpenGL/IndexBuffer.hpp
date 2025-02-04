#ifndef INDEX_BUFFER_HPP
#define INDEX_BUFFER_HPP

#include "GameEngineCore/Rendering/OpenGL/VertexBuffer.hpp"

namespace GameEngine {
    class IndexBuffer {
    public:
        IndexBuffer(const void *data, const size_t count,
                    const VertexBuffer::TypeDrawUsage usage = VertexBuffer::TypeDrawUsage::Static);
        ~IndexBuffer();

        IndexBuffer(const IndexBuffer&) = delete;
        IndexBuffer &operator=(const IndexBuffer&) = delete;

        IndexBuffer &operator=(IndexBuffer&&) noexcept;
        IndexBuffer(IndexBuffer&&) noexcept;

        void bind() const;
        static void unbind();
        size_t getCount() const { return m_count; }

    private:
        unsigned int m_id = 0;
        size_t m_count;
    };
}

#endif
