--C++ version: map<string, map<string, List<CraftObj>>> recipe
--C++ version 2.0: map<string, map<string, map<string, int>>>

local cTable = { 
	["Oxygen"] = 2,
	["Hydrogen"] = 5,
}

print("Lua is a fucking confusing peices of shit");


local recipe = { 
	["Water"] = {
		["Required"] = {
			["Oxygen"] = 2,
			["Hydrogen"] = 4,
		},
		["Result"] = {
			["Water"] = 2,
		},
		["Activated"] = true
	},
	["Sugar"] = {
		["Required"] = {
			["Carbon"] = 6,
			["Oxygen"] = 6,
			["Hydrogen"] = 12,
		},
		["Result"] = {
			["Sugar"] = 1,
		},
		["Activated"] = false
	}
}

local recipetobe = {
		["Required"] = {
			["Oxygen"] = 2,
			["Hydrogen"] = 3,
		},
		["Result"] = {
			["Water"] = 2,
		},
}

--Recipe dump
--[[
for key, value in pairs(recipe) do
	 print("\n Recipe items for: " .. key .. "\n")
	 for key2, value2 in pairs(recipe[key]["Required"]) do
	 	print(key2, value2)
	 end
	 print("\n Result items")
	 for key2, value2 in pairs(recipe[key]["Result"]) do
	 	print(key2, value2)
	 end
end
]]--

--t1 query table; t2 recipe to-be-matched
function match (t1, t2)
	itemstobematched = 0;
	itemsmatched = 0;

	for key, value in pairs(t2["Required"]) do
		itemstobematched = itemstobematched + 1;
	end

	for key, value in pairs(t1) do
		print (key .. value)
		for key2, value2 in pairs(t2["Required"]) do
			if key == key2 and value >= value2 then
				itemsmatched = itemsmatched + 1
			end
		end
	end

	if itemsmatched == itemstobematched then --If there is a complete match
		print("Complete Match. Removing Items from CraftTable...")
		for key, value in pairs(t1) do --Go through the CraftTable
			for key2, value2 in pairs(t2["Required"]) do --Go througyh RTB's required list
				print("checking " .. key .. "and " .. key2)
				if(key == key2) then --If the names match
					t1[key] = t1[key] - t2["Required"][key2] -- Element copy number = ECN - 
				end
			end		
		end
		for key, value in pairs(t2["Result"]) do
			print("adding..." .. key)
			player:addItem(Item:new(key))
		end --Go through recipe to be
	end

end

match(inputCraftTable, recipetobe)

print("End of file. Go fuck yourself.")
