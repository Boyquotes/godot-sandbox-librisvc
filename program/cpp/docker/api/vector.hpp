#pragma once
enum ClockDirection {
	CLOCKWISE = 0,
	COUNTERCLOCKWISE = 1,
};

#include "vector2.hpp"
#include "vector2i.hpp"
#include "rect2.hpp"
#include "rect2i.hpp"
#include "vector3.hpp"
#include "vector3i.hpp"
#include "vector4.hpp"
#include "vector4i.hpp"

namespace std
{
	inline void hash_combine(std::size_t &seed, std::size_t hash)
	{
		hash += 0x9e3779b9 + (seed << 6) + (seed >> 2);
		seed ^= hash;
	}

	template <>
	struct hash<Vector2>
	{
		std::size_t operator()(const Vector2 &v) const
		{
			std::size_t seed = 0;
			hash_combine(seed, std::hash<real_t>{}(v.x));
			hash_combine(seed, std::hash<real_t>{}(v.y));
			return seed;
		}
	};

	template <>
	struct hash<Vector2i>
	{
		std::size_t operator()(const Vector2i &v) const
		{
			std::size_t seed = 0;
			hash_combine(seed, std::hash<int>{}(v.x));
			hash_combine(seed, std::hash<int>{}(v.y));
			return seed;
		}
	};

	template <>
	struct hash<Rect2>
	{
		std::size_t operator()(const Rect2 &r) const
		{
			std::size_t seed = 0;
			hash_combine(seed, std::hash<real_t>{}(r.position.x));
			hash_combine(seed, std::hash<real_t>{}(r.position.y));
			hash_combine(seed, std::hash<real_t>{}(r.size.x));
			hash_combine(seed, std::hash<real_t>{}(r.size.y));
			return seed;
		}
	};

	template <>
	struct hash<Rect2i>
	{
		std::size_t operator()(const Rect2i &r) const
		{
			std::size_t seed = 0;
			hash_combine(seed, std::hash<int>{}(r.position.x));
			hash_combine(seed, std::hash<int>{}(r.position.y));
			hash_combine(seed, std::hash<int>{}(r.size.x));
			hash_combine(seed, std::hash<int>{}(r.size.y));
			return seed;
		}
	};

	template <>
	struct hash<Vector3>
	{
		inline std::size_t operator()(const Vector3 &v) const {
			register const Vector3 *vptr asm("a0") = &v;
			register std::size_t hash asm("a0");
			register int op asm("a2") = 0; // Vec3_Op::HASH
			register int syscall asm("a7") = 537; // ECALL_VEC3_OPS

			__asm__ volatile("ecall"
							: "=r"(hash)
							: "r"(op), "r"(vptr), "m"(*vptr), "r"(syscall));
			return hash;
		}
	};

	template <>
	struct hash<Vector3i>
	{
		std::size_t operator()(const Vector3i &v) const
		{
			std::size_t seed = 0;
			hash_combine(seed, std::hash<int>{}(v.x));
			hash_combine(seed, std::hash<int>{}(v.y));
			hash_combine(seed, std::hash<int>{}(v.z));
			return seed;
		}
	};

	template <>
	struct hash<Vector4>
	{
		std::size_t operator()(const Vector4 &v) const
		{
			std::size_t seed = 0;
			hash_combine(seed, std::hash<real_t>{}(v.x));
			hash_combine(seed, std::hash<real_t>{}(v.y));
			hash_combine(seed, std::hash<real_t>{}(v.z));
			hash_combine(seed, std::hash<real_t>{}(v.w));
			return seed;
		}
	};

	template <>
	struct hash<Vector4i>
	{
		std::size_t operator()(const Vector4i &v) const
		{
			std::size_t seed = 0;
			hash_combine(seed, std::hash<int>{}(v.x));
			hash_combine(seed, std::hash<int>{}(v.y));
			hash_combine(seed, std::hash<int>{}(v.z));
			hash_combine(seed, std::hash<int>{}(v.w));
			return seed;
		}
	};
}
