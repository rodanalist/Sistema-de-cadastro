production = Envie.production.with(:oauth) development = production.derive.with(:openid)

feature(:oauth) do # codigo que utiliza oauth end

feature(:openid) do # codigo que utiliza openid end 