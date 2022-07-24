local map = vim.api.nvim_set_keymap
local opts = { noremap = true, silent = true }

vim.g.mapleader = ' '

map('n', '<leader>e', ':NvimTreeFocus<CR>', opts)
map('n', '<leader>m', ':make<BAR>copen<CR>', opts)
