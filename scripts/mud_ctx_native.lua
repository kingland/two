-- mud library
-- mud ctx native module

function mud_ctx_backend()
    return mud_module("mud", "ctx-win", MUD_SRC_DIR, "ctx-win", nil, nil, nil, { mud.math, mud.ctx })
end
