class Processo:

    def __init__(self, id, descricao):
        self.id = id
        self.descricao = descricao
    
    def __eq__(self, other):
        if isinstance (other, Processo):
            return self.id == other.id and self.descricao == other.descricao
        return False
    
    # Método que define quando dois objetos Processo são considerados iguais
    def __hash__(self):
        return hash((self.id, self.descricao))
    
     # Necessário para usar objetos do tipo Processo em estruturas como conjuntos ou verificar duplicatas
    def __str__(self):
        return f"Processo [id = {self.id}, descricao = {self.descricao}]"
