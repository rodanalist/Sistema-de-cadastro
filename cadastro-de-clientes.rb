# app/models/cliente.rb
class Cliente < ApplicationRecord
    validates :nome, presence: true
    validates :email, presence: true, uniqueness: true
    validates :telefone, presence: true
  end
  
  # app/controllers/clientes_controller.rb
  class ClientesController < ApplicationController
    def index
      @clientes = Cliente.all
    end
  
    def show
      @cliente = Cliente.find(params[:id])
    end
  
    def new
      @cliente = Cliente.new
    end
  
    def create
      @cliente = Cliente.new(cliente_params)
      if @cliente.save
        redirect_to @cliente, notice: 'Cliente cadastrado com sucesso!'
      else
        render :new
      end
    end
  
    def edit
      @cliente = Cliente.find(params[:id])
    end
  
    def update
      @cliente = Cliente.find(params[:id])
      if @cliente.update(cliente_params)
        redirect_to @cliente, notice: 'Cliente atualizado com sucesso!'
      else
        render :edit
      end
    end
  
    def destroy
      @cliente = Cliente.find(params[:id])
      @cliente.destroy
      redirect_to clientes_url, notice: 'Cliente excluído com sucesso!'
    end
  
    private
  
    def cliente_params
      params.require(:cliente).permit(:nome, :email, :telefone)
    end
  end
  
  # app/views/clientes/index.html.erb
  <h1>Lista de Clientes</h1>
  <ul>
    <% @clientes.each do |cliente| %>
      <li><%= link_to cliente.nome, cliente %></li>
    <% end %>
  </ul>
  <%= link_to 'Novo Cliente', new_cliente_path %>
  
  # app/views/clientes/show.html.erb
  <h1>Detalhes do Cliente</h1>
  <p><strong>Nome:</strong> <%= @cliente.nome %></p>
  <p><strong>Email:</strong> <%= @cliente.email %></p>
  <p><strong>Telefone:</strong> <%= @cliente.telefone %></p>
  <%= link_to 'Editar', edit_cliente_path(@cliente) %> |
  <%= link_to 'Voltar', clientes_path %>
  
  # app/views/clientes/new.html.erb
  <h1>Novo Cliente</h1>
  <%= render 'form' %>
  <%= link_to 'Voltar', clientes_path %>
  
  # app/views/clientes/edit.html.erb
  <h1>Editar Cliente</h1>
  <%= render 'form' %>
  <%= link_to 'Voltar', clientes_path %>
  
  # app/views/clientes/_form.html.erb
  <%= form_with model: @cliente do |form| %>
    <% if @cliente.errors.any? %>
      <div id="error_explanation">
        <h2><%= pluralize(@cliente.errors.count, "erro") %> impediu o cadastro deste cliente:</h2>
        <ul>
          <% @cliente.errors.full_messages.each do |message| %>
            <li><%= message %></li>
          <% end %>
        </ul>
      </div>
    <% end %>
  
    <div class="field">
      <%= form.label :nome %>
      <%= form.text_field :nome %>
    </div>
  
    <div class="field">
      <%= form.label :email %>
      <%= form.email_field :email %>
    </div>
  
    <div class="field">
      <%= form.label :telefone %>
      <%= form.text_field :telefone %>
    </div>
  
    <div class="actions">
      <%= form.submit %>
    </div>
  <% end %>
  