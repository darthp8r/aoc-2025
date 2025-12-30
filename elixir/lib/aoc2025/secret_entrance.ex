defmodule Aoc2025.SecretEntrance do
  def secret_entrance data do
    Enum.map(data, fn(lyne) ->
      case String.at(lyne, 0) do
        "L" ->  -String.to_integer(String.slice(lyne, 1..-1//1))
        "R" ->  String.to_integer(String.slice(lyne, 1..-1//1))
      end
    end)
  end

  def zeroes turns do
    {_, combination} = Enum.reduce(turns, {50, 0}, fn(turn, memo) ->  # reverse of ruby binding
      {position, combination} = memo

      # 100+ because rem(-18, 100) yields -18
      position = rem(100+position+turn, 100)
      if (position == 0) do
        {position, combination+1}
      else
        {position, combination}
      end
    end)

    combination
  end

  def clicks turns do
    {_, combination} = Enum.reduce(turns, {50, 0}, fn(turn, memo) ->
      {position, combination} = memo
      combination =
        if turn < 0 do
          combination - div(turn, 100)
        else
          combination + div(turn, 100)
        end
      landing = position + rem(turn, 100)

      cond do
        landing < 0 ->
          if position == 0 do
            {landing+100, combination}
          else
            {landing+100, combination+1}
          end
        landing == 0 ->
          {landing, combination+1}
        landing < 100 ->
          {landing, combination}
        true ->
          {landing-100, combination+1}
      end
    end)

    combination
  end
end

