﻿#pragma once

#include <infra/Array.h>
#include <infra/Generic.h>
#include <type/Ref.h>
#include <ecs/Forward.h>
#include <ecs/ECS.h>
#include <ecs/SparseBuffer.h>

#include <stl/vector.h>

#define MUD_ECS_TYPED

namespace mud
{
	class ComponentBufferBase
	{
	public:
		virtual ~ComponentBufferBase() {}

		EntFlags m_flag;

#ifdef MUD_ECS_TYPED
		Type* m_type = nullptr;
#endif
		virtual void Clear() = 0;
		virtual void Add() = 0;
		virtual void Remove(uint32_t index) = 0;
		virtual Ref Get(uint32_t index) = 0;

		virtual void SortComponents() = 0;
	};

	template <class T>
	class ComponentBuffer : public ComponentBufferBase
	{
	public:
		ComponentBuffer() {}
#ifdef MUD_ECS_TYPED
		ComponentBuffer(Type& type, int bufferIndex, int capacity = 1 << 10)
#else
		ComponentBuffer(int bufferIndex, int capacity = 1 << 10)
#endif
		{
#ifdef MUD_ECS_TYPED
			m_type = &type;
#endif
			m_data.reserve(capacity);
			m_flag = uint64_t(1ULL << bufferIndex);
		}

		virtual void SortComponents() override
		{
			//quicksort(to_array(this->m_keys), to_array(this->m_data), this->m_indices);
		}

		virtual void Clear() override
		{
			m_data.clear();
		}

		virtual void Add() override
		{
			m_data.emplace_back();
		}

		virtual void Remove(uint32_t index) override
		{
			std::swap(m_data[index], m_data.back());
			m_data.pop_back();
		}

#ifdef MUD_ECS_TYPED
		virtual Ref Get(uint32_t index) override
		{
			return Ref(&m_data[index], *m_type);
		}
#endif

		vector<T> m_data;
	};
}