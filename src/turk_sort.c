/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:36:50 by aldokezer         #+#    #+#             */
/*   Updated: 2024/02/20 23:24:20 by aldokezer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// 500 499 498 497 496 495 494 493 492 491 490 489 488 487 486 485 484 483 482 481 480 479 478 477 476 475 474 473 472 471 470 469 468 467 466 465 464 463 462 461 460 459 458 457 456 455 454 453 452 451 450 449 448 447 446 445 444 443 442 441 440 439 438 437 436 435 434 433 432 431 430 429 428 427 426 425 424 423 422 421 420 419 418 417 416 415 414 413 412 411 410 409 408 407 406 405 404 403 402 401 400 399 398 397 396 395 394 393 392 391 390 389 388 387 386 385 384 383 382 381 380 379 378 377 376 375 374 373 372 371 370 369 368 367 366 365 364 363 362 361 360 359 358 357 356 355 354 353 352 351 350 349 348 347 346 345 344 343 342 341 340 339 338 337 336 335 334 333 332 331 330 329 328 327 326 325 324 323 322 321 320 319 318 317 316 315 314 313 312 311 310 309 308 307 306 305 304 303 302 301 300 299 298 297 296 295 294 293 292 291 290 289 288 287 286 285 284 283 282 281 280 279 278 277 276 275 274 273 272 271 270 269 268 267 266 265 264 263 262 261 260 259 258 257 256 255 254 253 252 251 250 249 248 247 246 245 244 243 242 241 240 239 238 237 236 235 234 233 232 231 230 229 228 227 226 225 224 223 222 221 220 219 218 217 216 215 214 213 212 211 210 209 208 207 206 205 204 203 202 201 200 199 198 197 196 195 194 193 192 191 190 189 188 187 186 185 184 183 182 181 180 179 178 177 176 175 174 173 172 171 170 169 168 167 166 165 164 163 162 161 160 159 158 157 156 155 154 153 152 151 150 149 148 147 146 145 144 143 142 141 140 139 138 137 136 135 134 133 132 131 130 129 128 127 126 125 124 123 122 121 120 119 118 117 116 115 114 113 112 111 110 109 108 107 106 105 104 103 102 101 100 99 98 97 96 95 94 93 92 91 90 89 88 87 86 85 84 83 82 81 80 79 78 77 76 75 74 73 72 71 70 69 68 67 66 65 64 63 62 61 60 59 58 57 56 55 54 53 52 51 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1

void	ft_find_closest_smaller_number_in_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_a;
	t_node	*current_b;
	t_node	*target_node;
	int32_t	a_value;
	long	best_match_value;

	current_a = stack_a->top;
	while (current_a != NULL)
	{
		best_match_value = LONG_MIN;
		a_value = current_a->value;
		current_b = stack_b->top;
		while (current_b != NULL)
		{
			if (current_b->value < a_value && current_b->value > best_match_value)
			{
				best_match_value = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
			if (best_match_value == LONG_MIN)
				current_a->target_node = ft_get_highest_val(stack_b);
			else
				current_a->target_node = target_node;
		}
		current_a = current_a->next;
	}
}

void	ft_find_closest_bigger_number_in_a(t_stack *stack_b, t_stack *stack_a)
{
	t_node	*current_a;
	t_node	*current_b;
	t_node	*target_node;
	int32_t	b_value;
	long	best_match_value;

	current_b = stack_b->top;
	while (current_b != NULL)
	{
		best_match_value = LONG_MAX;
		b_value = current_b->value;
		current_a = stack_a->top;
		while (current_a != NULL)
		{
			if (current_a->value > b_value && current_a->value < best_match_value)
			{
				best_match_value = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
			if (best_match_value == LONG_MAX)
				current_b->target_node = ft_get_smallest_val(stack_a);
			else
				current_b->target_node = target_node;
		}
		current_b = current_b->next;
	}
}

void	ft_move_nodes_from_a_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*cheapest;

	while (stack_b->size < 2 && stack_a->size > 3)
		ft_pb(stack_a, stack_b);
	while (stack_a->size > 3)
	{
		ft_index_stack(stack_a);
		ft_index_stack(stack_b);
		ft_calculcate_distance(stack_a);
		ft_calculcate_distance(stack_b);
		ft_find_closest_smaller_number_in_b(stack_a, stack_b);
		cheapest = ft_select_nodes_to_push(stack_a);
		ft_move_selected_nodes_to_top(stack_a, stack_b, cheapest);
		ft_pb(stack_a, stack_b);
	}
}

void	ft_move_nodes_from_b_to_a(t_stack *stack_b, t_stack *stack_a)
{
	t_node	*cheapest;

	while (stack_b->top != NULL)
	{
		ft_index_stack(stack_a);
		ft_index_stack(stack_b);
		ft_calculcate_distance(stack_a);
		ft_calculcate_distance(stack_b);
		ft_find_closest_bigger_number_in_a(stack_b, stack_a);
		cheapest = ft_select_nodes_to_push(stack_b);
		ft_move_selected_nodes_to_top_vb(stack_a, stack_b, cheapest);
		ft_pa(stack_b, stack_a);
	}
}

void	ft_turk_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*smallest_node;
	t_node	*biggest_node;

	ft_move_nodes_from_a_to_b(stack_a, stack_b);
	if (!ft_is_stack_sorted_asc(stack_a))
		ft_sort_three(stack_a);
	ft_move_nodes_from_b_to_a(stack_b, stack_a);
	ft_index_stack(stack_a);
	ft_calculcate_distance(stack_a);
	smallest_node = ft_get_smallest_val(stack_a);
	biggest_node = ft_get_highest_val(stack_a);
	if (smallest_node != stack_a->top)
	{
		while (stack_a->top != smallest_node)
		{
			if (smallest_node->r_distance < smallest_node->rr_distance)
				ft_ra(stack_a);
			else
				ft_rra(stack_a);
		}
	}
	//ft_traverse_stack(stack_a);
}
